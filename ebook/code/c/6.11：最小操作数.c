//解法一
//copyright@caopengcs     
//updated@July 08/12/2013    
class Solution    
{    
public:    
	// help 函数负责找到所有的路径    
	void help(intx,vector<int> &d, vector<string> &word,vector<vector<int> > &next,vector<string> &path,vector<vector<string> > &answer)
	{
		path.push_back(word[x]);    
		if (d[x] == 0)
		{   //已经达到终点了
			answer.push_back(path);    
		}    
		else
		{
			int i;    
			for (i = 0; i <next[x].size(); ++i)
			{
				help(next[x][i],d, word, next,path,answer);    
			}    
		}    
		path.pop_back();   //回溯    
	}    

	vector<vector<string>> findLadders(string start, string end, set<string>& dict)    
	{    
		vector<vector<string> > answer;    
		if (start == end)
		{   //起点终点恰好相等
			return answer;    
		}    
		//把起点终点加入字典的map    
		dict.insert(start);    
		dict.insert(end);    
		set<string>::iterator dt;    
		vector<string> word;    
		map<string,int>allword;    
		//把set转换为map，这样每个单词都有编号了。    
		for (dt = dict.begin(); dt!= dict.end(); ++dt)
		{
			word.push_back(*dt);    
			allword.insert(make_pair(*dt, allword.size()));    
		}    

		//建立连边 邻接表    
		vector<vector<int> > con;    
		int i,j,n =word.size(),temp,len = word[0].length();    
		con.resize(n);    
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j <len; ++j)
			{
				char c;    
				for (c =word[i][j] + 1; c <= 'z'; ++c)
				{  //根据上面第二种方法的优化版的思路，让每个单词每个位置变更大
					char last =word[i][j];    
					word[i][j] =c;    
					map<string,int>::iterator t = allword.find(word[i]);    
					if (t !=allword.end())
					{
						con[i].push_back(t->second);    
						con[t->second].push_back(i);    
					}    
					word[i][j] =last;    
				}    
			}    
		}    

		//以下是标准bfs过程    
		queue<int> q;    
		vector<int> d;    
		d.resize(n, -1);    
		int from = allword[start],to = allword[end];    
		d[to] = 0;  //d记录的是路径长度，-1表示没经过    
		q.push(to);    
		vector<vector<int> > next;    
		next.resize(n);    
		while (!q.empty())
		{
			int x = q.front(), now= d[x] + 1;    
			//now相当于路径长度  
			//当now > d[from]时，则表示所有解都找到了  
			if ((d[from] >= 0)&& (now > d[from]))
			{
				break;    
			}    
			q.pop();    
			for (i = 0; i <con[x].size(); ++i)
			{
				int y = con[x][i];    
				//第一次经过y  
				if (d[y] < 0)
				{
					d[y] = now;    
					q.push(y);    
					next[y].push_back(x);    
				}    
				//非第一次经过y  
				else if (d[y] ==now)
				{  //是从上一层经过的，所以要保存
					next[y].push_back(x);    
				}    
			}    
		}    
		if (d[from] >= 0)
		{  //有解
			vector<string>path;    
			help(from, d,word,next, path,answer);    
		}    
		return answer;    
	}    
};


//解法二
//copyright@fuwutu 6/26/2013  
class Solution  
{  
public:  
	vector<vector<string>> findLadders(string start, string end, set<string>& dict)  
	{  
		vector<vector<string>> result, result_temp;  
		if (dict.erase(start) == 1 && dict.erase(end) == 1)   
		{  
			map<string, vector<string>> kids_from_start;  
			map<string, vector<string>> kids_from_end;  

			set<string> reach_start;  
			reach_start.insert(start);  
			set<string> reach_end;  
			reach_end.insert(end);  

			set<string> meet;  
			while (meet.empty() && !reach_start.empty() && !reach_end.empty())  
			{  
				if (reach_start.size() < reach_end.size())  
				{  
					search_next_reach(reach_start, reach_end, meet, kids_from_start, dict);  
				}  
				else  
				{  
					search_next_reach(reach_end, reach_start, meet, kids_from_end, dict);  
				}  
			}  

			if (!meet.empty())  
			{  
				for (set<string>::iterator it = meet.begin(); it != meet.end(); ++it)  
				{  
					vector<string> words(1, *it);  
					result.push_back(words);  
				}  

				walk(result, kids_from_start);  
				for (size_t i = 0; i < result.size(); ++i)  
				{  
					reverse(result[i].begin(), result[i].end());  
				}  
				walk(result, kids_from_end);  
			}  
		}  

		return result;  
	}  

private:  
	void search_next_reach(set<string>& reach, const set<string>& other_reach, set<string>& meet, map<string, vector<string>>& path, set<string>& dict)  
	{  
		set<string> temp;  
		reach.swap(temp);  

		for (set<string>::iterator it = temp.begin(); it != temp.end(); ++it)  
		{  
			string s = *it;  
			for (size_t i = 0; i < s.length(); ++i)  
			{  
				char back = s[i];  
				for (s[i] = 'a'; s[i] <= 'z'; ++s[i])  
				{  
					if (s[i] != back)  
					{  
						if (reach.count(s) == 1)  
						{  
							path[s].push_back(*it);  
						}  
						else if (dict.erase(s) == 1)  
						{  
							path[s].push_back(*it);  
							reach.insert(s);  
						}  
						else if (other_reach.count(s) == 1)  
						{  
							path[s].push_back(*it);  
							reach.insert(s);  
							meet.insert(s);  
						}  
					}  
				}  
				s[i] = back;  
			}  
		}  
	}  

	void walk(vector<vector<string>>& all_path, map<string, vector<string>> kids)  
	{  
		vector<vector<string>> temp;  
		while (!kids[all_path.back().back()].empty())  
		{  
			all_path.swap(temp);  
			all_path.clear();  
			for (vector<vector<string>>::iterator it = temp.begin(); it != temp.end(); ++it)  
			{  
				vector<string>& one_path = *it;  
				vector<string>& p = kids[one_path.back()];  
				for (size_t i = 0; i < p.size(); ++i)  
				{  
					all_path.push_back(one_path);  
					all_path.back().push_back(p[i]);  
				}  
			}  
		}  
	}  
};  

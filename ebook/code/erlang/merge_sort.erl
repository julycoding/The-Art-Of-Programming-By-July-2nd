%% --------------------------------------------------------
%% @doc merge_sort
%% @author jpsiyu
%% @email jpsiyu@163.com
%% @create 2014/11/22
%% --------------------------------------------------------

-module(merge_sort).
-export([merge_sort/1, test/0]).

merge_sort(List) ->
	divide(List).

divide([X]) -> [X];
divide(List) ->
	R = length(List),
	M = trunc((1+R)/2),
	Left = lists:sublist(List, 1, M),
	Right = lists:sublist(List, M+1, R-M),
	MergeList = divide(Left) ++ divide(Right),
	merge(MergeList).

merge(List) ->
	P = 1, R = length(List), Q = trunc((P+R)/2),
	N1 = Q - P + 1,
	N2= R - Q,
	ListL = lists:sublist(List, P, N1) ++ [e],
	ListR = lists:sublist(List, Q+1, N2) ++ [e],
	merge_for(List, R, P, P, ListL, ListR, []).

merge_for(List, R, Li, Ri, ListL, ListR, OutputList) ->
	LValue = lists:nth(Li, ListL),
	RValue = lists:nth(Ri, ListR),
	if 
		LValue =:= e andalso RValue =:= e ->
			OutputList;
		LValue =:= e orelse LValue > RValue ->
			New = OutputList ++ [RValue],
			merge_for(List, R, Li, Ri+1, ListL, ListR, New);
		RValue =:= e orelse LValue =< RValue ->
			New = OutputList ++ [LValue],
			merge_for(List, R, Li+1, Ri, ListL, ListR, New);
		true ->
			OutputList
	end.


test() ->
	List = [1,6,3,9,7,5],
	divide(List).

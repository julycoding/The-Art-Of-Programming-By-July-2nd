import java.util.Collections;
import java.util.List;

/**
 * Select the K least numbers in a List
 * @author WangTaoTheTonic
 *
 */
public class TopK
{
	// version 1, pick the 0 to k element of the List quick sorted.
	public static List<Integer> topKV1(List<Integer> list, int k)
	{
		if(null == list || k > list.size())
			return null;
		if(k == list.size())
			return list;
		// self defined quickSort algorithm.
		quickSort(list, 0, list.size() - 1);
		// Collections.sort(List<T>) is a modified merge sort algorithm, which can be used here instead. 
		// Collections.sort(list);
		return list.subList(0, k);
	}
	
	// version 2, exchange the k least element to the front of List 
	public static List<Integer> topKV2(List<Integer> list, int k)
	{
		if(null == list || k > list.size())
			return null;
		int length = list.size();
		if(k == length)
			return list;
		int numI = 0;
		int numJ = 0;
		int temp = 0;
		for(int i = 0; i < k; i ++)
		{
			numI = list.get(i);
			for(int j = i + 1; j < length; j ++)
			{
				numJ = list.get(j);
				if(numJ < numI)
				{
					temp = numI;
					list.set(i, numJ);
					list.set(j, temp);
					numI = list.get(i);
				}
			}
		}
		return list.subList(0, k);
	}
	
	public static void quickSort(List<Integer> arr, int low, int high) {
		 
		if (null == arr || 0 == arr.size())
			return;
 
		if (low >= high)
			return;
 
		//pick the pivot
		int middle = low + (high - low) / 2;
		int pivot = arr.get(middle);
 
		//make left < pivot and right > pivot
		int i = low, j = high;
		while (i <= j) {
			while (arr.get(i) < pivot) {
				i++;
			}
 
			while (arr.get(j) > pivot) {
				j--;
			}
 
			if (i <= j) {
				int temp = arr.get(i);
				arr.set(i, arr.get(j));
				arr.set(j, temp);
				i++;
				j--;
			}
		}
 
		//recursively sort two sub parts
		if (low < j)
			quickSort(arr, low, j);
 
		if (high > i)
			quickSort(arr, i, high);
	}

}

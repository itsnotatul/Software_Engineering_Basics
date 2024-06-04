// binary search, find a target 
int fun(vector<int>& arr){
	int left = 0,right = arr.size()-1;

	while(left<=right){
		int mid = left + (right-left)/2;
		if(arr[mid] == target) return mid;
		if(arr[mid] > target) right = mid-1;
		else left = mid+1;
	}
	return left; // left is the insertion point, if the target doesn't exist
}

// bianry search with dupes, leftmost insertion point
/*
 1 2 2 3 4
 suppose need to find the leftmost 2, then it makes sens to have a equal sign in this pattern
 */
int fun(vector<int>& arr){
	int left =0,right = arr.size(); // if target doesn't exist and need to insert at the end. do dry run for better understanding

	while(left<right){
		int mid = left+(right-left)/2;
		if(arr[mid] >= target) right = mid;
		else left= mid+1;
	}
	return left;
}

// binary search with dupes, rightmost insertion. point

int fun(vector<int>& arr){
	int left =0,right =arr.size();

	while(left<right){
		int mid = left+(right-left)/2;
		if(arr[mid] >target) right = mid;
		else left = mid+1;
	}
	return left;
}

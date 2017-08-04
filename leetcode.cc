vector<int> twoSum(vector<int>& nums, int target) {

	unordered_map<int,int> H;
	
	for ( int i = 0; i < num.size(); i++ ) {
		
		auto it = H.find( target-nums[i] );
		
		if ( it != H.end() )
			return vector<int>{it->second,i};
		
		H[nums[i]] = i;
	}
	
return vector<int>();
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* addTwoNumbers( ListNode* l1, ListNode* l2 ) {
	
	int res = l1->val + l2->val;
	
	//TODO ListNode sentinel( -1 );
	ListNode* sum = new ListNode( res%10 );
	ListNode* head = sum;
	int carry = res >= 10 ? 1 : 0;
	l1 = l1->next; l2 = l2->next;
	while ( l1 || l2 ) {
		res = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
		ListNode* newnode = new ListNode( res%10 );
		sum->next = newnode; sum = newnode;
		carry = res >= 10 ? 1 : 0;
		l1 = l1 ? l1->next : nullptr;
		l2 = l2 ? l2->next : nullptr;
	}
	if (carry > 0) {
		ListNode* newnode = new ListNode( carry );
		sum->next = newnode; sum = newnode;
	}

return head;
}

//Given a string, find the length of the longest substring without repeating characters.
int lengthOfLongestSubstring(string s) {
	
	vector<int> lastseen(256,-1);
	
	int max = 0, start = -1;
		
	for ( int i = 0; i < s.size(); i++ ) {
		
		if ( lastseen[ s[i] ] >= start )
			start = lastseen[ s[i] ]+1;
		
		lastseen[ s[i] ] = i;
		
		if ( i-start+1 > max )
			max = i-start+1;
	}

return max;
}

//Reverse digits of an integer. return 0 when the reversed integer overflows.
int reverse(int x) {
	long int y = 0;
	while ( x ) {
		y = 10*y + x%10;
		x /= 10;
	}
	return y < INT_MIN || y > INT_MAX ? 0 : y;
}

/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
* n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
* Find two lines, which together with x-axis forms a container, such that the container 
* contains the most water.
*/
int maxArea(vector<int>& height) {
	int i = 0, j = height.size()-1, max = 0, vol;
	
	while ( i < j ) {
		
		if ( height[i] <= height[j] ) {
			vol = (j-i)*height[i];
			i++;
		} else {
			vol = (j-i)*height[j];
			j--;
		}
		
		if ( vol > max ) max = vol;
	}

return max;
}

// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
void recursive_perm ( vector<int>& b, int j, vector< vector<int> >& allperms ) {

	if ( j == b.size()-1 ) {
		allperms.emplace_back( b );
		for ( auto x : b ) cout << x << " ";
		cout << endl;
		return;
	}
	
	unordered_set<int> H;
	
	for ( int i = j; i < b.size(); i++ ) {
		if ( H.count( b[i] ) == 0 ) { H.emplace( b[i] ); }
		else { cout << "."; continue; }
		swap( b[i], b[j] );
		recursive_perm( b, j+1, allperms );
		swap( b[i], b[j] );
	}
}

vector<vector<int>> permuteUnique(vector<int>& a) {
	vector< vector<int> > allperms;
	vector<int> b( a );
	recursive_perm ( b, 0, allperms );
return allperms;
}

// Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
vector<int> searchRange(vector<int>& nums, int x) {
	
	int l = 0, r = nums.size()-1;
	
	int leftrange, rightrange;
	
	while ( l < r ) {
		int m = l + (r-l)/2;
		if ( nums[m] < x ) l = m+1;
		else if ( nums[m] > x ) r = m-1;
		else r = m;
	}
	if ( l == r && nums[l] == x ) leftrange = l;
	else return vector<int>{-1,-1};
	
	// EPI solution for leftrange
	//result = -1;
	//while ( l <= r ) {
		//int m = l + (r-l)/2;
		//if ( a[m] > x ) {
			//r = m-1;
		//} else if ( a[m] == x ) {
			//result = m; r = m-1;
		//} else {
			//l = m+1;
		//}
	//}
	//return result;
	
	r = nums.size()-1;
	while ( l < r ) {
		int m = l + (r-l)/2;
		if ( (r-l)%2 ) m++;
		if ( nums[m] < x ) l = m+1;
		else if ( nums[m] > x ) r = m-1;
		else l = m;
	}
	rightrange = l;
	return vector<int>{leftrange, rightrange};
}

void recursivelist( string& digits, string& sofar, int j, vector<string>& map, vector<string>& allcomb ) {
	if ( j == digits.size() ) {
		allcomb.push_back( sofar );
		return;
	}
	int d = atoi( digits.substr(j,1).c_str() );
	for ( int i = 0; i < map[d].size(); i++ ) {
		sofar.push_back( map[d][i] );
		recursivelist( digits, sofar, j+1, map, allcomb );
		sofar.pop_back();
	}
}

vector<string> letterCombinations(string digits) {
	vector<string> allcomb;
	vector<string> map = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	string A;
	recursivelist( digits, A, 0, map, allcomb );
	return allcomb;
}



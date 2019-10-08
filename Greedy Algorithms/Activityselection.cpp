// C++ program for activity selection problem. 
// The following implementation assumes that the activities 
// are already sorted according to their finish time 
#include<stdio.h> 
#include<vector> 
#include<algorithm>
#include <functional> 
// Prints a maximum set of activities that can be done by a single 
// person, one at a time. 
// n --> Total number of activities 
// s[] --> An array that contains start time of all activities 
// f[] --> An array that contains finish time of all activities 

// cost: O(N) where N is the number of activity

void printMaxActivities(int s[], int f[], int n) 
{ 
	int i, j; 

	printf ("Following activities are selected n"); 

	// The first activity always gets selected 
	i = 0; 
	printf("%d ", i); 

	// Consider rest of the activities 
	for (j = 1; j < n; j++) 
	{ 
	// If this activity has start time greater than or 
	// equal to the finish time of previously selected 
	// activity, then select it 
	if (s[j] >= f[i]) 
	{ 
		printf ("%d ", j); 
		i = j; 
	} 
	} 
} 


class width_elem {
public:
	int size;
	int min;
	int max;
	width_elem(int a,int b,int c) : size(a),min(b),max(c){}
}

// the complexity is N*log(N) but sorting for duration
// the algorithm has a better gready logic but require more memory
// a possible improvement in term of space and also time complexivity
// is to add an interval tree
// space complexity O(N) where N is the lenght of time sequence
void printMaxActivitiesImproved(int s[], int f[], int n) 
{ 
	int avaiable=0;
	int min = std::min_element(s,s+6);
	int max = std::max_element(f,f+6);
	int width = new int[6];
	int occupated_vect = new int[max-min];

	for(int k=0;k<6;k++)
		width[k] = f[k]-s[k];

	std::vector<int> aa;

	for(int k=0;k<6;k++){
		occupated_vect[k]=0;
		aa.push_back(width_elem(width[k],s[k],f[k]));
	}

	std::sort(aa.begin(),aa.end(),[](const width_elem& a,const width_elem& b) -> bool {
		return a.size > b.size;
	});

	auto iter = aa.begin();

	while(iter!=aa.end()){
		bool occupated=false;
		for (int k=0;(iter->min+k)<=iter->max;k++){
			if (occupated_vect[k]==0)
				occupated=true;
		}

		if (!occupated){
			for (int k=0;(iter->min+k)<=iter->max;k++){
				occupated_vect[k]=1;
			}
			avaiable++;
		}

		aa++;
	}

	return occupated;

} 

// driver program to test above function 
int main() 
{ 
	int s[] = {1, 3, 0, 5, 8, 5}; 
	int f[] = {2, 4, 6, 7, 9, 9}; 
	int n = sizeof(s)/sizeof(s[0]); 
	printMaxActivities(s, f, n); 
	return 0; 
} 

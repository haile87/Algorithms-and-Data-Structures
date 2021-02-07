#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct activitySelection{
	int startpoint, endpoint;
	inline activitySelection operator=(activitySelection x) {
        startpoint = x.startpoint;
        endpoint = x.endpoint;
        return x;
    }
};

bool compare(activitySelection j, activitySelection k){
    return (j.startpoint < k.startpoint);
}

void print_selected_activities(vector<activitySelection> y){
    // prints the activity with the latest starting time
    cout << "The Selected Activities are : { ";
    vector<activitySelection>::iterator viter = max_element(y.begin(), y.end(), compare);
    cout << "(" << viter->startpoint << "," << viter->endpoint << ") ";
    y.erase(viter);
    while(y.size()){
        vector<activitySelection>::iterator vit;
        vit = max_element(y.begin(), y.end(), compare);
        if((vit->endpoint)<=(viter->startpoint)){
            cout << "(" << vit->startpoint << "," << vit->endpoint << ") ";
            viter = vit;
        }
        y.erase(vit);
    }
    cout << "}" << endl;
}

int main(){
	activitySelection arr[] = {{4,8}, {0,2}, {7,9}, {3,5}};
	vector<activitySelection> activity;
	int i = 0;
	for(i=0;i<4;i++){
        activity.push_back(arr[i]);
    }
	print_selected_activities(activity);
	return 0;
}

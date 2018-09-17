//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

#include <vector>
#include <algorithm>

struct Workshop {
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops {
    int n;
    //Workshop* shops; //using vector instead
    /*
    Available_Workshops(int num) {
        n = num;
        shops = new Workshop[n];
    }*/
    vector<Workshop> shops;
};

bool operator <(const Workshop& lhs, const Workshop& rhs) {
    return (lhs.end_time < rhs.end_time);
}


Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops *works = new Available_Workshops();
    works->n = n;
    vector<int> end_time;
    for (int i = 0; i < n; i++) {
        end_time.push_back(start_time[i] + duration[i]);
        Workshop temp = {start_time[i], duration[i], start_time[i] + duration[i]};
        works->shops.push_back(temp);
    }
    sort(works->shops.begin(), works->shops.end());
    /*for (auto &i : works->shops) {
        cout << i.start_time << " ";
    }
    cout << endl;
    for (auto &i : works->shops) {
        cout << i.duration << " ";
    }
    cout << endl;
    for (auto &i : works->shops) {
        cout << i.end_time << " ";
    }
    cout << endl;*/
    
    return works;
}

int CalculateMaxWorkshops(Available_Workshops* works) {
    if (works->n == 0){
        return 0;
    } //else continue with algorithm
    
    int i = 0;  //workshop index
    int K = 1;  //first workshop to end should always be in your schedule selection
    
    //find next-soonest-to-end workshop
    while (i < works->n) {
        int j = i+1;
        while (j < works->n && works->shops[j].start_time < works->shops[i].end_time) {
            j++;
        }
        
        if (j < works->n) { //next workshop found
            //cout << j << " ";
            K++;
            i = j;
        } else { //out of workshops
            //cout << endl;
            return K;
        }
    }
    //cout << endl;
    return K;
}

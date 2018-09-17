class Person {
    public:
    string name;
    int age;

    virtual void getdata() {
    }
    
    virtual void putdata() {
        
    }
    
};

class Professor : public Person {
    private:
    int publications;
    static int cur_id;
    int my_id;
    
    public:
    virtual void getdata() {
        cur_id++;
        my_id = cur_id;
        cin >> name >> age >> publications;
    }
    virtual void putdata() {
        cout << name << " " << age << " " << publications << " " << my_id << endl;
    }
};

class Student : public Person {
    private:
    vector<int> marks;
    int marks_sum = 0;
    static int cur_id;
    int my_id;
    
    virtual void getdata() {
        cur_id++;
        my_id = cur_id;
        cin >> name >> age;
        for (int i = 0; i < 6; i++) {
            int mark;
            cin >> mark;
            marks.push_back(mark);
            marks_sum += mark;
        }
    }
    virtual void putdata() {
        cout << name << " " << age << " " << marks_sum << " " << my_id << endl;
    }
};

int Professor::cur_id = 0;
int Student::cur_id = 0;

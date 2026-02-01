#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <cmath>

using namespace std;

// 创建一个学生的类
class Student {
private:
    string id;
    string name;
    float score;
    float GPA;

public:
    Student(string id = "", string name = "", float score = 0.0f, float GPA = 0.0f) //构造函数的声明
        : id(id), name(name), score(score), GPA(GPA) {
    } //初始化列表

    string getId() const {
        return id;
    } //const的作用:只查询成员变量，不修改成员变量，调用更安全
    string getName() const {
        return name;
    }

    float getScore() const {
        return score;
    }

    float getGPA() const {
        return GPA;
    }

    void setId(string newID) {
        id = newID;
    }

    void setName(string newName) {
        name = newName;
    }

    void setScore(float newScore) {
        score = newScore;
    }

    void calculateGPA() {
        if (score < 60) {
            GPA = 0.0;
        } else {
            GPA = (score - 60.0) / 10.0 + 1.0;
        }
    }

    void display() const {
        cout << left << setw(12) << id //left:左对齐,setw():设置字符宽度，如果不足则补空格
                << setw(12) << name
                << setw(8) << fixed << setprecision(2) << score
                << setw(8) << fixed << setprecision(2) << GPA << endl;
    }
};

class StudentManagementSystem {
private:
    vector<Student> students; //创建一个数据库，元素是学生(类)
    struct RankNode {
        Student *ptr;
        int rank;
        RankNode *next;
    };

    RankNode *rankHead = nullptr;

    void deleteRankList() {
        while (rankHead != nullptr) {
            //删掉已有的链表
            RankNode *temp = rankHead;
            rankHead = rankHead->next;
            delete temp;
        }
    }

    void buildRankList(bool descending = false) {
        deleteRankList();
        rankHead = nullptr;
        if (students.size() == 0) {
            return;
        }
        vector<pair<float, int> > scoreIndex;
        for (int i = 0; i < students.size(); i += 1) {
            scoreIndex.push_back(pair<float, int>(students[i].getScore(), i));
        }
        sort(scoreIndex.begin(), scoreIndex.end(),
             [descending](const pair<float, int> &a, const pair<float, int> &b) {
                 return !((a.first > b.first) ^ descending);
             });
        /*使用异或运算，根据descending的结果决定是否反转返回值，1则反转，否则不反转
         * 然后再取反，也就是说，在这里如果是降序，实际上是升序，因为后面构建链表排列还会再反转一次*/
        for (int i = 0; i < scoreIndex.size(); i += 1) {
            RankNode *newNode = new RankNode; //头插法，排列反转一次
            newNode->ptr = &students[scoreIndex[i].second];
            newNode->rank = scoreIndex.size() - i;
            newNode->next = rankHead;
            rankHead = newNode;
        }
        if (rankHead == nullptr) {
            return;
        }
        RankNode *current = rankHead;
        while (current->next != nullptr) {
            //同分同位次
            if ((current->ptr->getScore() - current->next->ptr->getScore()) < 1E-6) {
                current->next->rank = current->rank;
            }
            current = current->next;
        }
    }

    void displayHeader() const {
        for (int i = 0; i < 50; i++) {
            cout << "=";
        }
        cout << endl;
        cout << left << setw(12) << "Student ID"
                << setw(12) << "Name"
                << setw(8) << "Score"
                << setw(8) << "GPA" << endl; //setw()的作用:保证输出内容可以对齐，更美观
        for (int i = 0; i < 32; i++) {
            cout << "-";
        }
        cout << endl;
    }

public:
    int queryStudent(string IdOrName) {
        //支持输入id或者名字
        int isIdFound = 0;
        int isNameFound = 0;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == IdOrName) {
                isIdFound = 1;
                students[i].display();
                cout << endl;
            } else if (students[i].getName() == IdOrName) {
                isNameFound = 1;
                students[i].display();
                cout << endl;
            }
        }
        return isIdFound || isNameFound;
    }

    void addStudent() {
        string id, name;
        float score;
        float GPA;

        cout << "Enter student ID: ";
        string tempID;
        cin >> tempID;
        bool isIdDuplicate = false;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == tempID) {
                isIdDuplicate = true;
                break;
            }
        }
        if (!isIdDuplicate) {
            id = tempID;
        } else {
            queryStudent(tempID);
            cout << "ID duplicated, Please try another one.";
            return;
        }
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter score: ";

        while (!(cin >> score)) {
            //循环只在(cin>>score)为false时运行，表示一直询问有效成绩，直到遇到有效成绩为止
            cout << "Please enter a valid number: ";
            cin.clear(); //清除输入
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //作用:丢弃错误输入，否则会死循环
        }
        if (score < 60) {
            GPA = 0.0;
        } else {
            GPA = (score - 60.0) / 10.0 + 1.0;
        }
        Student s(id, name, score, GPA); //先创建一个类的实例
        students.push_back(s); //再存入数据库中
        cout << "Student added successfully!" << endl;
    }

    int displayAll() const {
        if (students.empty()) {
            cout << "No student records found!" << endl;
            return 0;
        }

        displayHeader(); //把表头先打印好
        for (const auto &student: students) {
            //遍历students容器中的每一个元素
            student.display(); //使用Student的成员函数打印自身数据
        }
        for (int i = 0; i < 50; i++) {
            cout << "=";
        }
        cout<<endl;
        return 1;
    }

    void sortByScore(bool descending = false) {
        //默认降序排列
        deleteRankList(); //链表已失效
        sort(students.begin(), students.end(),
             [descending](const Student &a, const Student &b) {
                 return (a.getScore() > b.getScore()) ^ descending;
             }); // 使用异或运算，根据descending的结果决定是否反转返回值，1则反转，否则不反转
        if (descending) {
            cout << "Students were sorted by descending" << endl;
        } else {
            cout << "Students were sorted by ascending" << endl;
        }
    }

    void deleteStudent() {
        if (students.empty()) {
            cout << "No students to delete!" << endl;
            return;
        }
        displayAll(); //先列出所有学生，以决定到底要删除哪个
        cout << "Enter student ID to delete: ";
        string id;
        cin >> id;

        bool isStudentFound = false;
        for (auto it = students.begin(); it != students.end();) {
            //it是迭代器，指向students数组中的某个student
            if (it->getId() == id) {
                students.erase(it); //删除容器中的这个学生
                deleteRankList();
                rankHead = nullptr;
                isStudentFound = true;
                cout << "Student deleted successfully!" << endl;
                return; //找到之后直接退出函数，因为id是唯一的，删掉了就是删掉了，没有第二个相同id的学生
            } else {
                it += 1; //继续递增迭代器
            }
        }

        if (!isStudentFound) {
            cout << "Student with ID " << id << " not found!" << endl;
        }
    }

    void modifyStudent() {
        deleteRankList();
        rankHead = nullptr;
        rankHead = nullptr;
        if (students.empty()) {
            cout << "No students to modify!" << endl;
            return;
        }
        displayAll(); //先列出所有学生，以决定到底要删除哪个
        cout << "Enter student ID to modify: ";
        string id;
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        bool isStudentFound = false;
        for (auto it = students.begin(); it != students.end();) {
            if (it->getId() == id) {
                cout << "Student found, edit ID, Press enter to skip:";
                isStudentFound = true;
                string tempID;
                getline(cin, tempID);
                cout << endl;
                if (tempID != "") {
                    bool isIdDuplicate = false;
                    for (int i = 0; i < students.size(); i++) {
                        //ID去重
                        if (students[i].getId() == tempID) {
                            isIdDuplicate = true;
                            break;
                        }
                    }
                    if (isIdDuplicate) {
                        cout << "ID duplicated, Please try another one." << endl;
                        queryStudent(tempID);
                        return;
                    }
                    it->setId(tempID); // 不重复才设置
                }
                cout << "Edit name, Press enter to skip:";
                string tempName;
                getline(cin, tempName);
                cout << endl;
                if (tempName != "") {
                    it->setName(tempName);
                }
                cout << "Edit score, Press enter to skip:";
                float tempscore, GPA;
                while (!(cin >> tempscore)) {
                    //循环只在(cin>>score)为false时运行，表示一直询问有效成绩，直到遇到有效成绩为止
                    cout << "Please enter a valid number: ";
                    cin.clear(); //清除输入
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //作用:丢弃错误输入，否则会死循环
                }
                it->setScore(tempscore);
                it->calculateGPA();
                cout << "Student modified successfully!" << endl;
                return;
            } else {
                it += 1; //继续递增迭代器
            }
        }

        if (!isStudentFound) {
            cout << "Student with ID " << id << " not found!" << endl;
        }
    }


    void getStatistics() {
        float sum = 0;
        int below60 = 0;
        int _60to70 = 0;
        int _70to80 = 0;
        int _80to90 = 0;
        int _90to100 = 0;
        for (auto it = students.begin(); it != students.end(); it++) {
            float score = it->getScore();
            sum += it->getScore();
            if (score >= 90) _90to100++;
            else if (score >= 80) _80to90++;
            else if (score >= 70) _70to80++;
            else if (score >= 60) _60to70++;
            else below60++;
        }
        int above60 = _90to100 + _80to90 + _70to80 + _60to70;
        float passRate = (float) above60 / students.size() * 100; // 加*100显示百分比
        float average = sum / students.size();
        float varianceSum = 0;
        for (const auto &s: students) {
            float diff = s.getScore() - average;
            varianceSum += diff * diff;
        }
        float variance = varianceSum / students.size();
        float stdDev = sqrt(variance);

        cout << "Average score: " << average << endl;
        cout << "Standard deviation: " << stdDev << endl;
        cout << "Pass Rate:" << passRate << "%"<<endl;
        cout << "count of 90~100:" << _90to100 << endl;
        cout << "count of 80~90:" << _80to90 << endl;
        cout << "count of 70~80:" << _70to80 << endl;
        cout << "count of 60~70:" << _60to70 << endl;
    }

    void saveToFile() {
        ofstream out("students.txt");
        if (!out) {
            cout << "Failed to open file for writing!" << endl;
            return;
        }

        out << students.size() << endl;
        for (const auto &s: students) {
            out << s.getId() << endl;
            out << s.getName() << endl;
            out << s.getScore() << endl;
            out << s.getGPA() << endl;
        }
        out.close();
        cout << "Data saved to students.txt successfully!" << endl;
    }

    void loadFromFile() {
        ifstream in("students.txt");
        if (!in) {
            cout << "No existing data file found." << endl;
            return;
        }

        students.clear();
        deleteRankList();
        rankHead = nullptr;

        int n;
        in >> n;
        in.ignore();

        for (int i = 0; i < n; i++) {
            string id, name;
            float score, gpa;

            getline(in, id);
            getline(in, name);
            in >> score;
            in >> gpa;
            in.ignore();

            students.emplace_back(id, name, score, gpa);
        }
        in.close();
        cout << "Loaded " << n << " students from file." << endl;
    }

    void showMenu() const {
        cout << "\n===== Student Management System =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Sort by Score" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Modify Student" << endl;
        cout << "6. Query Student" << endl;
        cout << "7. Get Statistics" << endl;
        cout << "8. Save to File" << endl; // 新增
        cout << "9. Load from File" << endl; // 新增
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        return;
    }

    void run() {
        while (true) {
            // 无限循环，直到用户选择退出
            showMenu();

            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    addStudent();
                    break;
                case 2:
                    displayAll();
                    break;
                case 3:
                    sortByScore();
                    break;
                case 4:
                    deleteStudent();
                    break;
                case 5:
                    modifyStudent();
                    break;
                case 6: {
                    string input;
                    cout<<"Please enter ID or name:";
                    cin >> input;
                    if (!queryStudent(input)) {
                        cout<<"No such student found!"<<endl;
                    }
                    break;
                }
                case 7:
                    getStatistics();
                    break;
                case 8:
                    saveToFile();
                    break;
                case 9:
                    loadFromFile();
                    break;
                case 0:
                    cout << "Thank you for using the system. Goodbye!" << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl; // 输入均不符合，提示重新输入
                    break;
            }
        }
    }

    ~StudentManagementSystem() {
        //删掉链表
        deleteRankList();
    }
};

int main() {
    StudentManagementSystem sms; // 创建类的实例
    sms.run();
    return 0;
}

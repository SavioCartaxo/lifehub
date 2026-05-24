#include <iostream>
#include "models/Task.hpp"

using namespace std;
using namespace lifehub;

int main() {
    
    string title = "Estudar C++";
    string activityType = "Study";
    Task t1(title, activityType);

    cout << "Title: " << t1.getTitle() << endl;
    cout << "Activity: " << t1.getActivityType() << endl;
    cout << "Time: " << t1.getInvestedTime() << endl;
    cout << "Finished: " << t1.isFinished() << endl;

    cout << "\n--- Updating task ---\n";

    t1.increaseTime(2.5);
    t1.finish();

    cout << "Time: " << t1.getInvestedTime() << endl;
    cout << "Finished: " << t1.isFinished() << endl;

    return 0;
}
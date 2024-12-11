#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Member {
protected:
    string name;
    int membershipID;
    bool isMember;

public:
    Member(string name, int membershipID, bool isMember)
        : name(name), membershipID(membershipID), isMember(isMember) {
    }

    void renewMembership() {
        isMember = true;
        cout << "Членство оновлено для: " << name << endl;
    }

    virtual void display() const {
        cout << "Ім'я: " << name << endl
            << "ID: " << membershipID << endl
            << "Членство: " << (isMember ? "Активовано" : "Не активовано") << endl;
    }
};

class PremiumMember : public Member {
private:
    int rewardPoints;

public:
    PremiumMember(string name, int membershipID, bool isMember, int rewardPoints)
        : Member(name, membershipID, isMember), rewardPoints(rewardPoints) {
    }

    void addPoints(int points) {
        rewardPoints += points;
        cout << "Додано " << points << " балів. Загалом: " << rewardPoints << endl;
    }

    void display() const override {
        Member::display();
        cout << "Бали винагород: " << rewardPoints << endl;
    }
};

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Member member("Джейн Остен", 1, false);
    member.display();
    cout << endl;

    member.renewMembership();
    member.display();
    cout << endl;

    PremiumMember premiumMember("Френк Сінатра", 2, true, 250);
    premiumMember.display();
    cout << endl;

    premiumMember.renewMembership();
    premiumMember.addPoints(50);
    premiumMember.display();

    return 0;
}

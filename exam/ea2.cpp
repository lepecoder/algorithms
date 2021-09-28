#include <iostream>
#include <memory.h>
class vector3 {
  public:
    vector3() : mX(0.0f), mY(0.0f), mZ(0.0f) {}
    vector3(float x, float y, float z) : mX(x), mY(y), mZ(z) {}
    ~vector3() {}

    vector3 operator+(const vector3 &right) {
        vector3 temp(mX + right.mX, mY + right.mY, mZ + right.mZ);
        return temp;
    }

    bool operator!=(const vector3 &right) {
        return !((mX != right.mX) || (mY != right.mY) || (mZ != right.mZ));
        // if ((mX != right.mX) || (mY != right.mY) || (mZ != right.mZ)) { return false; }
        // return true;
    }

    void SetX(float x) { mX = x; }
    void SetY(float y) { mY = y; }
    void SetZ(float z) { mZ = z; }

  private:
    float mX;
    float mY;
    float mZ;
};

class Person {
  public:
    // Person() {
    // memset(mName, 0, 255);
    // mNext = NULL;
    // mIsMale = false;
    // mPosition.SetX(0.0f);
    // mPosition.SetY(0.0f);
    // mPosition.SetZ(0.0f);
    // mId = sUniqueId++;
    // }
    Person() : mNext(NULL), mIsMale(false), mPosition(), mId(sUniqueId++) { memset(mName, 0, 255); }

    ~Person() {}

    bool operator!=(const Person &right) {
        if ((memcmp(mName, right.mName, 255) != 0) || (mIsMale != right.mIsMale) || (mPosition != right.mPosition) || (mId != right.mId) ||
            (mNext != right.mNext)) {
            return true;
        }

        return false;
    }

    char mName[255];
    bool mIsMale;
    vector3 mPosition;
    int mId;
    Person *mNext;

    static int sUniqueId;
};

int Person::sUniqueId = 0;

class AI {
  public:
    AI();
    ~AI();
    void MovePeople(bool moveLeft);

  private:
    Person *GetFirstNonMovingPerson();
    Person *GetFirstPerson();
    Person *GetNextPerson(Person person);

    Person *mPersonList;
};

AI::AI() {
    mPersonList = new Person;
    Person *person = mPersonList;
    for (int i = 0; i < 1000; i++) {
        person->mNext = new Person;
        person = person->mNext;
    }
}
AI::~AI() {
    Person *p = mPersonList;
    Person *next = p->mNext;
    while (p) {
        delete p;
        p = next;
        next = p->mNext;
    }
}

Person *AI::GetFirstPerson() { return mPersonList; }

Person *AI::GetNextPerson(Person person) { return person.mNext; }

Person *AI::GetFirstNonMovingPerson() {
    Person *person = mPersonList;
    /* The first 500 people are always moving, the second 500 are not moving.*/
    while (person->mId < 500) { person = person->mNext; }

    return person;
}

void AI::MovePeople(bool moveLeft) {
    for (Person *person = GetFirstPerson(); person != GetFirstNonMovingPerson(); person = GetNextPerson(*person)) {
        vector3 moveAmount;
        if (moveLeft) {
            moveAmount.SetX(-10);
            moveAmount.SetY(10);
            moveAmount.SetZ(10);

            person->mPosition = person->mPosition + moveAmount;
        } else {
            moveAmount.SetX(10);
            moveAmount.SetY(10);
            moveAmount.SetZ(10);

            person->mPosition = person->mPosition + moveAmount;
        }
    }
}

int main() {
    AI testAI;
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) testAI.MovePeople(i % 2 == 0);
    std::cout << "Finish";
    return 0;
}
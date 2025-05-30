#include<bits/stdc++.h>
using namespace std;

//Subscriber abstract class
class ISubscriber {
public:
    virtual void update() = 0;
    virtual ~ISubscriber() {};
};

//Channel abstract class
class IChannel {
public:
    virtual void subscribe(ISubscriber* s) = 0;
    virtual void unsubscribe(ISubscriber* s) = 0;
    virtual void notifySubscribers () = 0;
    virtual ~IChannel() {};
};

//Concrete class Subscriber
class Channel : public IChannel {
private:
    string name;
    string newVideo;
    vector<ISubscriber*> subscribers;

public:
    Channel(const string& name) {
        this -> name = name;
    }

    void subscribe(ISubscriber* s) override {
        if(find(subscribers.begin(), subscribers.end(), s) == subscribers.end())
            subscribers.push_back(s);
    }
    void unsubscribe(ISubscriber* s) override{
        auto it = find(subscribers.begin(), subscribers.end(), s);
            subscribers.erase(it);
    }

    void uploadVideo(const string& videoTitle) {
        newVideo = videoTitle;
        cout << name << " has just uploaded " << newVideo << endl;
        notifySubscribers();
    }

    void notifySubscribers() override {
        for(ISubscriber* s : subscribers) {
            s -> update();
        }
    }

    string getVideo() {
        return "\n Checkout! " + name + "has uploaded " + newVideo + "\n";
    }
};

//concrete Subscriber class
class Subscriber : public ISubscriber {
private:
    Channel* channel;
    string name;
public:
    Subscriber(const string& name, Channel* channel) {
        this -> name = name;
        this -> channel = channel;
    }

    void update() override {
        cout << "Hi! " + name + "," + channel -> getVideo();
    }
};

int main () {
    Channel* channel = new Channel("SkillBox");
    Subscriber* subscriber1 = new Subscriber("Ashutosh Rathore", channel);
    Subscriber* subscriber2 = new Subscriber("Mahender", channel);
    Subscriber* subscriber3 = new Subscriber("Ishan Gupta", channel);

    channel -> subscribe(subscriber1);
    channel -> subscribe(subscriber2);
    channel -> subscribe(subscriber3);

    channel -> uploadVideo("How to do Pike PushUp");
    channel -> unsubscribe(subscriber3);
    channel -> uploadVideo("The Delusional Game");
    channel -> unsubscribe(subscriber2);

    return 0;
}
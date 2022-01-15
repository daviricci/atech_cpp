//
// Created by davim on 15/01/2022.
//
#include "core.h"

namespace core {
    // message
    Message::Message(std::string topic, std::string msg):topic(std::move(topic)),msg(std::move(msg)){}
    Message::~Message(){}
    std::string Message::get_msg(){return this->msg;}
    std::string Message::get_topic(){return this->topic;}
    //
    //Subscriber
    Subscriber::Subscriber() {}
    Subscriber::~Subscriber() {}
    void Subscriber::add_topic(std::string topic) {this->topics.push_back(topic);}
    void Subscriber::show_message() {
        while(!this->msgs.empty()){
            Message msg = this->msgs.front();
            this->msgs.pop();
            std::cout<<msg.get_msg()<<std::endl;
        }}
    //
    //Broker
    Broker::Broker(){}
    Broker::~Broker(){}
    void Broker::forward(){
        while(!this->msgs.empty()){
            Message msg = this->msgs.front();
            this->msgs.pop();
            for(int i=0; i<this->subscribers.size();i++){
                std::vector<std::string>::iterator topic;
                for(topic = this->subscribers.at(i)->topics.begin();topic !=this->subscribers.at(i)->topics.end();++topic){
                    std::string str_topic = *topic;
                    if(str_topic==msg.get_topic()){
                        this->subscribers.at(i)->msgs.push(msg);
                    }
                }
            }
        }
    }
    void Broker::subscribe(Subscriber *subscriber){this->subscribers.push_back(subscriber);}
    void Broker::receive(Message &new_message){this->msgs.push(new_message);}
    //
    //Publisher
    Publisher::Publisher(){}
    Publisher::~Publisher(){}
    void Publisher::send_msg(Message &new_message, Broker &my_server){
        my_server.receive(new_message);
    }
    //
    //User
    User::User(std::string topic_signature, Broker *broker): topic_signature(topic_signature), broker(broker){}
    User::~User() {}
    void User::send_message(std::string msg) {
        Message send_msg(this->topic_signature,msg);
        this->publisher.send_msg(send_msg, *this->broker);
    }
    void User::add_contact(std::string topic) {
        this->subscriber.add_topic(topic);
    }
    void User::show_message() {
        this->subscriber.show_message();
    }
    Subscriber *User::get_subscriber(){
        return &this->subscriber;
    }
};
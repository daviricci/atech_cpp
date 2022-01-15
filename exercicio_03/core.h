//
// Created by davim on 15/01/2022.
//

#ifndef EXERCICIO_03_CORE_H
#define EXERCICIO_03_CORE_H

#include <string>
#include <vector>
#include <queue>

namespace core {
    class Message{
        public:
            Message(std::string topic, std::string msg);
            ~Message();
            std::string get_msg();
            std::string get_topic();
        private:
            std::string topic;
            std::string msg;
    };

    class Subscriber{
        public:
            Subscriber();
            ~Subscriber();
            void show_message();
            void add_topic(std::string topic);
            std::vector<std::string> topics;
            std::queue<Message> msgs;
    };

    class Broker{
        public:
            Broker();
            ~Broker();
            void forward();
            void subscribe(Subscriber *subscriber);
            void receive(Message &new_message);

        private:
            std::queue<Message> msgs;
            std::vector<Subscriber*> subscribers;
    };

};


#endif //EXERCICIO_03_CORE_H

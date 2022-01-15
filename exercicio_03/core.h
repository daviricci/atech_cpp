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

    class Publisher{
        public:
            Publisher();
            ~Publisher();
            void send_msg(Message &new_message, Broker &my_server);
    };

    class User{
        /*
         * Todo usuário é um Publisher e um Subscriber
         * Quando o usuário atuar como Publisher, toda mensagem enviada terá um tópico fixo,
         * sendo esse sua assinatura.
         * Todo usuário tem seu vetor de tópicos de seus contatos, quais deseja receber
         * mensagens, quando atuar como Subscriber
         */
        public:
            User(std::string topic_signature, Broker *broker);
            ~User();
            void send_message(std::string msg);
            void add_contact(std::string topic);
            void show_message();
            Subscriber *get_subscriber();
        private:
            std::string topic_signature;
            Broker *broker;
            Publisher publisher;
            Subscriber subscriber;
    };
};


#endif //EXERCICIO_03_CORE_H

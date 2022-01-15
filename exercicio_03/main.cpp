#include <iostream>
#include "core.h"
int main() {
    core::Broker Server;
    core::User Davi("Davi",&Server);
    core::User Paulo("Paulo",&Server);
    core::User Daniel("Daniel",&Server);

    Server.subscribe(Davi.get_subscriber());
    Server.subscribe(Paulo.get_subscriber());
    Server.subscribe(Daniel.get_subscriber());

    Davi.add_contact("Paulo");
    Davi.add_contact("Daniel");

    Paulo.add_contact("Davi");
    Paulo.add_contact("Daniel");

    Daniel.add_contact("Davi");
    Daniel.add_contact("Paulo");

    Davi.send_message("Eu, Davi, estou com covid19");
    Davi.send_message("Já fiz dois exames e ambos deram positivos");

    Server.forward();
    Paulo.show_message();
    Daniel.show_message();


    return 0;
}

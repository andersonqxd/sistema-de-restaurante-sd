#include "Message.hpp"


Message::Message( MesssageType message_type, int request_id, std::string object_reference, int method_id ) 
{
    this->message_type = message_type;
    this->request_id = request_id;
    this->object_reference = object_reference;
    this->method_id = method_id;
}


json Message::to_json()
{
    json object;

    object[ "message_type" ] = message_type;
    object[ "request_id" ] = request_id;
    object[ "object_reference" ] = object_reference;
    object[ "method_id" ] = method_id;

    return object;
}

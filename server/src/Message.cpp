#include "Message.hpp"


Message::Message( MesssageType message_type, int request_id, std::string object_reference, int method_id, std::string arguments ) 
{
    this->message_type = message_type;
    this->request_id = request_id;
    this->object_reference = object_reference;
    this->method_id = method_id;
    this->arguments = arguments;
}


json Message::to_json()
{
    json object;

    object[ "message_type" ] = message_type;
    object[ "request_id" ] = request_id;
    object[ "object_reference" ] = object_reference;
    object[ "method_id" ] = method_id;
    object[ "arguments" ] = arguments;

    return object;
}


MesssageType Message::get_message_type()
{
    return message_type;
}

int Message::get_request_id()
{
    return request_id;
}

std::string Message::get_object_reference()
{
    return object_reference;
}

int Message::get_method_id()
{
    return method_id;
}

std::shared_ptr<std::string> Message::get_arguments()
{
    return std::make_shared<std::string>(arguments);
}



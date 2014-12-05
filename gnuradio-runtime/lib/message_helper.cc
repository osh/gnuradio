#include <gnuradio/message_helper.h>
#include <gnuradio/io_signature.h>

gr::message_helper::message_helper(std::string name) :
        gr::block( name, gr::io_signature::make(0,0,0), gr::io_signature::make(0,0,0)),
        port(pmt::mp(name))
    {
        message_port_register_in(port);
        message_port_register_out(port);
    }

void gr::message_helper::post(pmt::pmt_t msg){
        message_port_pub(port, msg);
    }


gr::message_helper_sptr gr::make_message_helper_sptr(std::string name){
    return boost::shared_ptr<message_helper>(new message_helper(name));
    }




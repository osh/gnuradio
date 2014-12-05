#ifndef MESSAGE_HELPER_H
#define MESSAGE_HELPER_H 1

#include <gnuradio/block.h>
namespace gr {
class message_helper;
typedef boost::shared_ptr<message_helper> message_helper_sptr;
message_helper_sptr make_message_helper_sptr(std::string name);
class message_helper : public block {
    private:
        pmt::pmt_t port;
    public:
        message_helper(std::string name);
        void post(pmt::pmt_t msg);
    };
}
#endif

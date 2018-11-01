//
// Created by fy on 18-11-1.
//

#include <eosiolib/eosio.hpp>

using namespace eosio;

CONTRACT base : public eosio::contract {
public:
    using contract::contract;
  
    // 要注意静态变量的生存期，每次执行action都会重新初始化内存
    const static int i = 111;
    static int i2;

    // hi action
    ACTION hi(capi_name hi_name){
        require_auth(hi_name);
        i2++;
        print("name is ", name{hi_name}, " ", i2, "\n"); // i2每次运行都是1

        // 这里会触发一个inline action， 注意区分C++中的inline函数
        INLINE_ACTION_SENDER( base, ping )( "base"_n, {name{hi_name},"active"_n}, {hi_name} );
        
        require_recipient("hello"_n); // 注意这里会以receiver为hello code为base action为hi来执行action
    }

    ACTION ping(capi_name p_name){
        require_auth(p_name);
        i2++;
        print("ping name is ", name{p_name}, " ", i2, "\n");
    }

};

static int i3 = 23;

extern "C" {
   void apply(uint64_t receiver, uint64_t code, uint64_t action){
       print("apply ", name{receiver}, " ", name{code}, " ", name{action}, "\n");
       print("i ", base::i, " ", base::i2, " ", i3, "\n");
       auto cc = new int;
       print("pi ", (int)cc, "\n");

       // 这里支持简单处理，一般要验证receiver，code是不是期望的
       // EOSIO_DISPATCH 中只在 receiver == code的时候才处理
       switch(action){
           case name("hi").value:
           {
                 eosio::execute_action(name{receiver}, name{code}, &base::hi);
                 break;
           }
           case name("ping").value:
           {
                 eosio::execute_action(name{receiver}, name{code}, &base::ping);
                 break;
           }
           default:
           {
               print("no support");
           }
       }
   }
}

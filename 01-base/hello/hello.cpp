#include <eosiolib/eosio.hpp>
#include <boost/mp11/tuple.hpp>
using namespace eosio;

// Hello 合约

CONTRACT hello : public eosio::contract {
  public:
      using contract::contract;

      ACTION hi( name user ) {
         require_auth( name{user} );
         print( "Hello, ", name{user} );
      }
};

//EOSIO_DISPATCH( hello, (hi) )

// 基本等同于上面的宏
extern "C" {
   void apply(uint64_t receiver, uint64_t code, uint64_t action){
       print("apply ", name{receiver}, " ", name{code}, " ", name{action}, "\n");
       if(receiver != code){
           eosio_assert(false, "receiver != code!");
           return;
       }
       switch(action){
           case name("hi").value:
           {
                 execute_action(name{receiver}, name{code}, &hello::hi);
                 break;
           }
           default:
           {
                 print("no support act");
           }
       }
       
   }
}
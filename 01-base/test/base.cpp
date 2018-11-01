//
// Created by fy on 18-11-1.
//

#include <eosiolib/eosio.hpp>

using namespace eosio;

CONTRACT test : public eosio::contract {
public:
    using contract::contract;
};

extern "C" {
   void apply(uint64_t receiver, uint64_t code, uint64_t action){
       print("apply ", name{receiver}, " ", name{code}, " ", name{action}, "\n");
       switch(action){
           case name("transfer").value:
           {
               require_recipient("hello"_n);
           }
       }
   }
}

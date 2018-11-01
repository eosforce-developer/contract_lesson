cmake_minimum_required(VERSION 3.5)
project(base VERSION 1.0.0)

include_directories(/usr/local/eosio.cdt/include)

find_package(eosio.cdt)

# add contract
add_contract( base base base.cpp )
cmake_minimum_required(VERSION 3.5)
project(template_example VERSION 1.0.0)

find_package(eosio.cdt)

include_directories(/usr/local/eosio.cdt/)

# add contract
add_contract( hello hello hello.cpp )

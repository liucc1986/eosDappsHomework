#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
#include <eosiolib/asset.hpp>
#include <eosiolib/action.hpp>
#include <eosiolib/symbol.hpp>
#include <eosiolib/singleton.hpp>
#include <eosiolib/print.hpp>
#include <eosiolib/transaction.hpp>
#include <eosiolib/crypto.h> 
#include <eosiolib/dispatcher.hpp>

using namespace eosio;
using namespace std;
class luckygame : public contract{
    public:
        using contract::contract;
        [[eosio::action]]
        void transfer (name user){
            require_auth(_self);
            print("player:",name(user));
            
            //内联调用 语法说明
		    //action(
            //permission_level, //权限
            //code, 合约
            //action, 合约方法
            //data); 调用数据
            action(
                permission_level{_self,name("active")},
                name("eosio.token"),
                name("transfer"),
                std::make_tuple(_self,user,asset(10,symbol("SYS",4)),std::string("game send SYS"))
            ).send();


        }
};
EOSIO_DISPATCH(luckygame,(transfer));


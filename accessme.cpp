#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
using namespace eosio;

class accessme : public eosio::contract {
  private:
    /// @abi table
    struct nugget {
      uint64_t      id;  // primary key
      account_name  owner;      // account name for the user
      std::string   name;      // the note message
      std::string   value;      // the note message
      std::string   key;      // TODO: Can this be String?
      uint64_t      expiry; // the store the last update block time

      // primary key
      auto primary_key() const { return id; }
      // secondary key: user
      account_name get_by_user() const { return owner; }
    };

    // create a multi-index table and support secondary key
    typedef eosio::multi_index< N(nugget), nugget,
      indexed_by< N(getbyuser), const_mem_fun<nugget, account_name, &nugget::get_by_user> >
      > nuggets;

  public:
    using contract::contract;

    /// @abi action
    void createnugget( uint64_t _id, account_name _owner, std::string& _name, std::string& _value, std::string& _key, uint64_t _expiry) {
      // to sign the action with the given account
      require_auth( _owner );

      nuggets obj(_self, _self); // code, scope

      // TODO: Check for unique key
      obj.emplace( _owner, [&]( auto& address ) {
        address.id      = _id;
        address.owner   = _owner;
        address.name    = _name;
        address.value   = _value;
        address.key     = _key;
        address.expiry  = _expiry;
      });
    }

};

// specify the contract name, and export a public action: update
EOSIO_ABI( accessme, (createnugget) )


# CONTRACT FOR accessme::createnugget
The parties of this contract are the originator of the action ({{_owner}}) and the
entity receiving plain text version of the `_key` to encrypt `_value` (The Recipient)

## ACTION NAME: createnugget

### Parameters
Input parameters:

* `_id` (Unique integer serving as the primary key)
* `_owner` (Account name of the user providing the data)
* `_name` (Name of the datanugget)
* `_value` (Value of the datanugget)
* `_key` (Encrypted key to decrypt the `_value`)
* `_expiry` (Amount of seconds after which )

### Intent
INTENT. Intent of this smart contract is to share sensitive information from {{_owner}} to The Recipient.
The Recipient is obligated to destroy all the data (encrypted or decrypted form)
supplied by this action and all references to such data after {{_expiry}} seconds has elapsed.

### Term
TERM. This contract does not have an expiration date other than defined by the relevant jurisdictions.



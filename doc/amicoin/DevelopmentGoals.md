## AMICoin Development Goals

![Logo](https://github.com/amicoin/amicoin/raw/master/doc/amicoin/smiley.png "Logo")

The overall aim of AMICoin is to be a user-friendly crypto-currency. To achieve this, it will go beyond 
the features that many other crypto-currencies offer. It is taken for granted nowdays that a crypto-
currency needs an infrastructure of wallets (desktop and mobile), block explorers, exchnage suport, 
an informative website, a support forum etc. However even with all these in place, many new users 
do not feel comfortable using a crypto-currency...

One diffciulty comes from handling crypto-addresses, namely the strings of letters/digits etc. 
do not make sense to most users. For instance sending money to a crypto-address like: 
`t1dXqTEP1UHvvtBN9JNMG9vDcPAQjU7goAe` is not so
intuitive. It cannot be memorized (for sure) and before sending, one needs to double check the 
address is the right one. To make it easier for users, we need to make using crypto-currency as 
easy as using e-mail...

To this end, one feature that AMICoin will develop is "friendly addresses":
Users who send coins will send them to an address like `joe.smith@abc.com` or just `Joe Smith`. 
It will be the responsibility of wallet software to translate this to a specific crypto-address
like `t1dXqTEP1UHvvtBN9JNMG9vDcPAQjU7goAe` but users will not see this. At the same time a global 
distributed registry of mapping friendly addresses (e.g. `Joe Smith`) to crypto-addresses 
(e.g. `t1dXqTEP1UHvvtBN9JNMG9vDcPAQjU7goAe`) will be mainatined on the blockchain. Users who are 
setting up new wallets will just type their desired friendly address (e.g. `Joe Smith`) and the 
corresponding crypto-address will be hidden from them (by default). This will make the experience 
easier for new users.

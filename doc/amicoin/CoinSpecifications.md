## AMICoin Specifications

![Logo](https://github.com/amicoin/amicoin/raw/master/doc/amicoin/smiley.png "Logo")

This document contains the technical details of AMICoin. It requires some understanding of 
crypto-currency by the reader. Basic explanations are provided as well as external links to 
resorces that contain more detailed information on the basic terms. 

In order to send and receive AMICoins every user needs to have an AMICoin wallet. A wallet may be a 
program for a desktop PC or mobile device. The wallet hosts AMICoin addresses. An address is similar 
toa bank account that may be used to send and receive money. One difference though is that an
AMICoin wallet has many addresses (typically) and not just one. An AMICoin address is a sequence of
letters and digits like `t1dXqTEP1UHvvtBN9JNMG9vDcPAQjU7goAe`. There are two types of addresses 
supported:
1. Transparent (T) addresses - their transaction details are publicly visible. Everyone who knows 
the address may see what coins were received or sent from it and when.
2. Private (Z) addresses - their transaction details are private. Only the sender and recipient know 
the details of who sent/received how many coins and when. These addresses are useful for online 
financial privacy.

All AMICoin transactions are propagated across a peer-to-peer network of AMICoin Nodes. A node may 
be a desktop or a server computer or less likely a mobile device. Every node sees all transactions,
validates them and stores them in its own copy of the transaction history called a 
[blockchain](https://en.wikipedia.org/wiki/Blockchain). The transactions in roughly every
2.5 minute interval are gathered in one block and propagated across the network. Blocks of 
transactions are validated/confirmed by [miners](https://en.bitcoin.it/wiki/Mining) who make 
the network secure. Miners get rewarded for their work with newly generated AMICoins. Approximately
every 2.5 minutes there are 12.5 new AMICoins created.

#### Technical details:

Name                | Value
--------------------|-----------------
Block Time:            | 2.5 minutes
Block Reward:          | 12.5 AMICoin 
Genesis block started: | Jan 2019
Hash algorithm:        | Equihash
Difficulty Adjustment: | Digishield V3
Reward Halving:        | Every 4 years (same as Bitcoin)
Total AMICoin Supply:  | 21,000,000 (same as Bitcoin)




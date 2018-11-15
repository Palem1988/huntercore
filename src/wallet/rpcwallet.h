// Copyright (c) 2016-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_WALLET_RPCWALLET_H
#define BITCOIN_WALLET_RPCWALLET_H

#include <map>
#include <string>

class CCoinControl;
class CRPCTable;
class CWallet;
class CWalletTx;
class JSONRPCRequest;
class UniValue;

typedef std::map<std::string, std::string> mapValue_t;

void RegisterWalletRPCCommands(CRPCTable &t);

/**
 * Figures out what wallet, if any, to use for a JSONRPCRequest.
 *
 * @param[in] request JSONRPCRequest that wishes to access a wallet
 * @return nullptr if no wallet should be used, or a pointer to the CWallet
 */
std::shared_ptr<CWallet> GetWalletForJSONRPCRequest(const JSONRPCRequest& request);

std::string HelpRequiringPassphrase(CWallet *);
void EnsureWalletIsUnlocked(CWallet *);
bool EnsureWalletIsAvailable(CWallet *, bool avoidException);
CTransactionRef SendMoneyToScript(CWallet* pwallet, const CScript& scriptPubKey,
                                  const CTxIn* withInput, CAmount nValue,
                                  bool fSubtractFeeFromAmount,
                                  const CCoinControl& coin_control,
                                  mapValue_t mapValue, std::string fromAccount);

UniValue getaddressinfo(const JSONRPCRequest& request);
UniValue signrawtransactionwithwallet(const JSONRPCRequest& request);
#endif //BITCOIN_WALLET_RPCWALLET_H

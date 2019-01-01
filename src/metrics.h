// Copyright (c) 2016 The Zcash developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "uint256.h"

#include <atomic>
#include <mutex>
#include <string>

struct AtomicCounter {
    std::atomic<uint64_t> value;

    AtomicCounter() : value {0} { }

    void increment(){
        ++value;
    }

    void decrement(){
        --value;
    }

    int get() const {
        return value.load();
    }
};

class AtomicTimer {
private:
    std::mutex mtx;
    uint64_t threads;
    int64_t start_time;
    int64_t total_time;

public:
    AtomicTimer() : threads(0), start_time(0), total_time(0) {}

    /**
     * Starts timing on first call, and counts the number of calls.
     */
    void start();

    /**
     * Counts number of calls, and stops timing after it has been called as
     * many times as start().
     */
    void stop();

    bool running();

    uint64_t threadCount();

    double rate(const AtomicCounter& count);
};

extern AtomicCounter transactionsValidated;
extern AtomicCounter ehSolverRuns;
extern AtomicCounter solutionTargetChecks;
extern AtomicTimer miningTimer;

void TrackMinedBlock(uint256 hash);

void MarkStartTime();
double GetLocalSolPS();
int EstimateNetHeightInner(int height, int64_t tipmediantime,
                           int heightLastCheckpoint, int64_t timeLastCheckpoint,
                           int64_t genesisTime, int64_t targetSpacing);

void TriggerRefresh();

void ConnectMetricsScreen();
void ThreadShowMetricsScreen();

/**
 * Heart image: https://commons.wikimedia.org/wiki/File:Heart_coraz%C3%B3n.svg
 * License: CC BY-SA 3.0
 *
 * Rendering options:
 * Zcash: img2txt -W 40 -H 20 -f utf8 -d none -g 0.7 Z-yellow.orange-logo.png
 * Heart: img2txt -W 40 -H 20 -f utf8 -d none 2000px-Heart_corazón.svg.png
 */
const std::string METRICS_ART =
		"                                        [0;1;30;90;43m8@XXXSSS%%[0m                                        \n"
		"                         [0;33;5;40;100mX[0;1;30;90;43m8[0;33;47m88[0;1;33;93;47m8@[0;37;5;43;103m;;;;;;;;;;;;;;;;;;;;[0;33;5;43;103m:::::::;S8[0;1;33;93;43m8[0;1;30;90;43m   [0m                         \n"
		"                  [0;33;5;40;100m;[0;1;30;90;47mt[0;1;33;93;47mS[0;1;37;97;47m8[0;37;5;47;107m:[0;1;37;97;47m888888[0;1;33;93;47mS[0;37;5;43;103m:::::.................:[0;33;5;43;103m......:::::::;;S[0;1;33;93;43m8[0;1;30;90;43m  [0m                  \n"
		"             [0;33;5;40;100mt[0;1;30;90;47m.[0;1;37;97;47m8[0;37;5;47;107m::::..........[0;1;37;97;47m8[0;37;5;43;103m.......................[0;33;5;43;103m       ......:::::;;@[0;1;30;90;43m  [0m             \n"
		"          [0;1;30;90;47m%[0;1;37;97;47m8[0;37;5;47;107m::::.........    [0;1;37;97;47m8[0;1;33;93;47m@XX8[0;37;5;43;103mt...................[0;33;5;43;103m :X88S.       ....::::;;@[0;1;30;90;43m [0m          \n"
		"       [0;33;5;40;100m;[0;1;33;93;47mS[0;1;37;97;47m888[0;37;5;47;107m::......       [0;33;47m@[0;33;5;40;100m8[0;32;40m.[0;34;40m    [0;32;40m [0;1;30;90;40m8[0;1;30;90;43m8[0;37;5;43;103m:...............[0;1;30;90;43m%[0;32;40m@ [0;34;40m    [0;32;40m.[0;1;30;90;43m.[0;1;33;93;43m8[0;33;5;43;103m         ....:::;;X[0;1;30;90;43m [0m       \n"
		"     [0;37;43m8[0;37;5;43;103mt;;[0;1;33;93;47mXSS[0;1;37;97;47m888[0;37;5;47;107m..        [0;1;37;97;47m8[0;1;33;93;47m@[0;32;40m [0;34;40m         [0;1;30;90;43m8[0;37;5;43;103m..............[0;1;30;90;43m%[0;34;40m         [0;32;40m [0;33;5;43;103mS           ...::::;t[0;1;30;90;43m [0m     \n"
		"    [0;37;5;43;103m@;;;:::...............:[0;33;5;40;100m8[0;32;40m.[0;34;40m       [0;30;5;40;100mS[0;37;5;43;103m@.............[0;33;5;43;103m t[0;30;5;40;100mS[0;34;40m       [0;32;40m.[0;1;30;90;43m [0;33;5;43;103m.             ...:::;;S[0;32;40m8[0m   \n"
		"   [0;37;5;43;103mSt;;;:::.................%[0;37;43mX[0;1;30;90;43m8@@88[0;37;5;43;103m@.............[0;33;5;43;103m     S[0;1;30;90;43m..   [0;1;33;93;43mX[0;33;5;43;103mt                ...:::;;%[0m   \n"
		"  [0;1;30;90;43m8[0;37;5;43;103mtt;;;::...................................[0;33;5;43;103m                                 ....:::;;[0;1;30;90;43m [0m  \n"
		"  [0;1;30;90;43m@[0;37;5;43;103mtt;;;::..............................[0;33;5;43;103m                                      ....:::;;[0;1;30;90;43m [0m  \n"
		"   [0;33;5;43;103m%;:::[0;37;5;43;103m;::.........[0;33;5;43;103mS[0;1;30;90;43m%[0;1;33;93;43mX[0;37;5;43;103m.........[0;33;5;43;103m                                   [0;1;33;93;43m@[0;1;30;90;43m [0;33;5;43;103mX        ...:::;;%[0m   \n"
		"    [0;33;5;43;103mX;::::...X88[0;1;33;93;43m88@[0;1;30;90;40m8[0;33;5;40;100m8[0;33;5;43;103mX                                              S[0;1;30;90;43m [0;32;40m@[0;1;33;93;43m@88[0;33;5;43;103m88@...:::;;S[0;32;40m8[0m   \n"
		"     [0;1;30;90;43m [0;33;5;43;103mt;::::...    .[0;1;33;93;43m8[0;1;30;90;43m.[0;33;5;40;100m8[0;1;30;90;43m:[0;1;33;93;43m8[0;33;5;43;103m;                                      ;[0;1;33;93;43m8[0;1;30;90;43m   [0;1;33;93;43m@[0;33;5;43;103m.    ...::::;t[0;1;30;90;43m [0m     \n"
		"       [0;1;30;90;43m [0;33;5;43;103mX;;:::....    .8[0;1;30;90;43m     [0;1;33;93;43mS[0;33;5;43;103m8t                          ;8[0;1;33;93;43mS[0;1;30;90;43m     [0;33;5;43;103m8.    ....:::;;X[0;1;30;90;43m [0m       \n"
		"          [0;1;30;90;43m [0;33;5;43;103m@;;::::....     :8[0;1;33;93;43mS[0;1;30;90;43m           [0;1;33;93;43mSXX@@XXS[0;1;30;90;43m           [0;1;33;93;43mS[0;33;5;43;103m8:     ....::::;;@[0;1;30;90;43m [0m          \n"
		"             [0;1;30;90;43m  [0;33;5;43;103m8;;:::::......      .tS8[0;1;33;93;43m88XSS%%SSX88[0;33;5;43;103m8St.      ......:::::;;@[0;1;30;90;43m  [0m             \n"
		"                  [0;1;30;90;43m  [0;1;33;93;43m8[0;33;5;43;103mS;;:::::::............................:::::::;;S[0;1;33;93;43m8[0;1;30;90;43m  [0m                  \n"
		"                         [0;1;30;90;43m   [0;1;33;93;43m@[0;33;5;43;103m8S;;;::::::::::::::::::::::;;;S8[0;1;33;93;43m@[0;1;30;90;43m   [0m                         \n"
		"                                        [0;1;30;90;43m          [0m                                        \n";



//
// Created by HuaJuan on 2022/11/13.
//

#ifndef DS2022_LAB07_STU_MAXTRANSMISSIONPROBAPROLEM_H
#define DS2022_LAB07_STU_MAXTRANSMISSIONPROBAPROLEM_H

#include <vector>

double maxTransmissionProba(int n,
                            const std::vector<std::vector<int>> &links,
                            const std::vector<double> &successProbas,
                            int start,
                            int end);

#endif //DS2022_LAB07_STU_MAXTRANSMISSIONPROBAPROLEM_H

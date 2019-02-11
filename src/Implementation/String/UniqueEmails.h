//
// Created by Jacob Lo on 2019-01-17.
//

// EASY
// https://leetcode.com/problems/unique-email-addresses/

#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

namespace UniqueEmails {
    string uniqueEmail(string &email) {

        int posDot = email.find('.');
        while ( posDot < email.find('@') &&  posDot != string::npos ) {
            email.erase(posDot, 1);
            posDot = email.find('.', posDot);
        }

        int posPlus = email.find('+');
        if (posPlus != string::npos) {
            email.erase(posPlus, email.find('@') - posPlus);
        }

        return email;
    }

    int numUniqueEmails(vector<string> &emails) {
        unordered_set<string> res;
        for (auto e : emails) {
            res.insert(uniqueEmail(e));
        }
        return res.size();
    }

    void test() {
        vector<string> r {"j+d.j.b.k.xr.mmp@rn.qyy.com","j+yt+w.on.k.r+i.l@rn.qyy.com","j+i.t.b.o.x.l.s.a.z@rn.qyy.com","j+wteuapmm.y@rn.qyy.com","q.z.y.znvz.d+l+p@kyf.com","np.e.x+u.a+mbv+j@uadsua.rqda.com","np.e.x+e.f.n.f.r.c@uadsua.rqda.com","pdiykt.rh+cc@ta.bxx.com","j+aqlxgyy+b.k@rn.qyy.com","j+a.hm.y.t.j.d+qq@rn.qyy.com","k.i.j.hy.pe.n+ea@xfeslns.com","j+h.v.w.b+x+h.e.n.r@rn.qyy.com","j+m+j.k.o.jl.vv+r@rn.qyy.com","k.i.j.hy.pe.n+l+i@xfeslns.com","k.i.j.hy.pe.n+nh@xfeslns.com","j+akd.xb.xx+c.e@rn.qyy.com","j+a.j.u+e.s.p+w.x.x@rn.qyy.com"};
        int result = numUniqueEmails(r);
        int correct = 5;
        cout << correct << " " << result;
    }
}
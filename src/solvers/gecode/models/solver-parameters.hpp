/*
 *  Main authors:
 *    Roberto Castaneda Lozano <roberto.castaneda@ri.se>
 *    Mats Carlsson <mats.carlsson@ri.se>
 *    Rodothea Myrsini Tsoupidi <tsoupidi@kth.se>
 *
 *  Contributing authors:
 *    Daniel Lundén <daniel.lunden@sics.se>
 *
 *  This file is part of Unison, see http://unison-code.github.io
 *
 *  Copyright (c) 2016, RISE SICS AB
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived from this
 *     software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef __SOLVER_RESULT_PARAMETERS__
#define __SOLVER_RESULT_PARAMETERS__

#include <iostream>
#include <limits>
#include <algorithm>
#include <limits>
#include <vector>
#include <set>
#include <string>
#include <sstream>

// #include <gecode/int.hh>

#include "common/util.hpp"
#include "common/definitions.hpp"

// using namespace Gecode;
using namespace std;

class SolverParameters {

public:

  // Program parameters
  vector<int> registers;

  vector<int> instructions;

  vector<int> cycles;

  vector<int> temporaries;

  string solver;

  bool has_solution;

  bool proven;

  vector<int> cost;

  int failures;

  int nodes;

  int presolver_time;

  int gecode_presolving_time;

  int solver_time;

  int global_int_variables;

  int global_bool_variables;

  int global_set_variables;

  SolverParameters(JSONVALUE root);

protected:

  SolverParameters() {};
  void get_element(JSONVALUE root, bool & b);
  void get_element(JSONVALUE root, double & d);
  void get_element(JSONVALUE root, int & i);
  void get_element(JSONVALUE root, string & s);


  JSONVALUE getRoot(JSONVALUE root, string p);

  template<class T>
  T get_scalar(JSONVALUE root) {
    T i;
    get_element(root, i);
    return i;
  }

  template<class T>
  vector<T> get_vector(JSONVALUE root) {
    vector<T> vi;
    get_element(root, vi);
    return vi;
  }

#ifdef GRAPHICS

  template<class T>
  void get_element(QScriptValue root, vector<T> & vi) {
    assert(root.isArray());
    QScriptValueIterator iti(root);
    while (iti.hasNext()) {
      iti.next();
      if (iti.name() != "length") {
        T e;
        get_element(iti.value(), e);
        vi.push_back(e);
      }
    }
  }

#else

  template<class T>
  void get_element(Json::Value root, vector<T> & vi) {
    assert(root.isArray());
    Json::ValueIterator iti = root.begin();
    while (iti != root.end()) {
      T e;
      get_element(*iti, e);
      vi.push_back(e);
      iti++;
    }
  }

#endif



};

#endif

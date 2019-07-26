# distutils: language = c++
# distutils: sources = ../src/treap.cc
from libcpp cimport bool

cdef extern from "../../src/streamingcc_include/treap.h" namespace "streamingcc":
    cdef cppclass Treap:
        Treap() except +
        void insert(int val)
        bool contains(int val)

cdef class PyTreap:
    cdef Treap treap
    def __cint__(self):
        self.treap = Treap()
    def insert(self, val):
        self.treap.insert(val)
    def contains(self, val):
        self.treap.contains(val)


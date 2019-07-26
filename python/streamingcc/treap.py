import streamingcc._treap as _treap

Treap = _treap.PyTreap

class TP:
    def __init__(self):
        self._tp = Treap()

    def insert(self, val):
        self._tp.insert(val)

    def contains(self, val):
        self._tp.contains(val)

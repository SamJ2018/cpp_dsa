#pragma once

//�ж�a�Ƿ�С��b
template<typename T> static bool It(T* a, T* b) { return It(*a, *b); }

template<typename T> static bool It(T& a, T& b) { return a < b; }

//�ж�a�Ƿ����b
template<typename T> static bool eq(T* a, T* b) { return It(*a, *b); }
template<typename T>static bool eq(T& a, T& b) { return a == b; }
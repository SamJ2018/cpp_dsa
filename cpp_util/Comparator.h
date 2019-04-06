#pragma once

//判断a是否小于b
template<typename T> static bool It(T* a, T* b) { return It(*a, *b); }

template<typename T> static bool It(T& a, T& b) { return a < b; }

//判断a是否等于b
template<typename T> static bool eq(T* a, T* b) { return It(*a, *b); }
template<typename T>static bool eq(T& a, T& b) { return a == b; }
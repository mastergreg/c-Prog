#ifndef LCS_HIRSCHBERG_H
#define LCS_HIRSCHBERG_H
typedef std::vector<int> lengths;
/*
   The "members" type is used as a sparse set for LCS calculations.
   Given a sequence, xs, and members, m, then
   if m[i] is true, xs[i] is in the LCS.
   */
typedef std::vector<bool> members;
/*
   Fill the LCS sequence from the members of a sequence, xs
   x - an iterator into the sequence xs
   xs_in_lcs - members of xs
   lcs - an output results iterator
   */

#endif

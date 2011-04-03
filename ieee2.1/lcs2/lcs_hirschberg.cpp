

/*
   C++ implementation of 
   "A linear space algorithm for computing maximal common subsequences"
   D. S. Hirschberg
http://portal.acm.org/citation.cfm?id=360861

See also: http://wordaligned.org/articles/longest-common-subsquence
*/
#include "lcs_hirschberg.h"
//#include 
  template <typename it, typename ot>
void set_lcs(it x, members const & xs_in_lcs, ot lcs)
{
  for (members::const_iterator xs_in = xs_in_lcs.begin();
      xs_in != xs_in_lcs.end(); ++xs_in, ++x)
  {
    if (*xs_in)
    {
      *lcs++ = *x;
    }
  }
}
/*
   Calculate LCS row lengths given iterator ranges into two sequences.
   On completion, `lens` holds LCS lengths in the final row.
   */
  template <typename it>
void lcs_lens(it xlo, it xhi, it ylo, it yhi, lengths & lens)
{
  // Two rows of workspace.
  // Careful! We need the 1 for the leftmost column.
  lengths curr(1 + distance(ylo, yhi), 0);
  lengths prev(curr);

  for (it x = xlo; x != xhi; ++x)
  {
    swap(prev, curr);
    int i = 0;
    for (it y = ylo; y != yhi; ++y, ++i)
    {
      curr[i + 1] = *x == *y
        ? prev[i] + 1
        : std::max(curr[i], prev[i + 1]);
    }
  }
  swap(lens, curr);
}
/*
   Recursive LCS calculation.
   See Hirschberg for the theory!
   This is a divide and conquer algorithm.
   In the recursive case, we split the xrange in two.
   Then, by calculating lengths of LCSes from the start and end
   corners of the [xlo, xhi] x [ylo, yhi] grid, we determine where
   the yrange should be split.

   xo is the origin (element 0) of the xs sequence
   xlo, xhi is the range of xs being processed
   ylo, yhi is the range of ys being processed
   Parameter xs_in_lcs holds the members of xs in the LCS.
   */
template <typename it>
  void
calculate_lcs(it xo, it xlo, it xhi, it ylo, it yhi, members & xs_in_lcs)
{
  unsigned const nx = distance(xlo, xhi);

  if (nx == 0)
  {
    // empty range. all done
  }
  else if (nx == 1)
  {
    // single item in x range.
    // If it's in the yrange, mark its position in the LCS
    xs_in_lcs[distance(xo, xlo)] = find(ylo, yhi, *xlo) != yhi;
  }
  else
  {
    // split the xrange
    it xmid = xlo + nx / 2;

    // Find LCS lengths at xmid, working from both ends of the range
    lengths ll_b, ll_e;
    std::reverse_iterator<it> hix(xhi), midx(xmid), hiy(yhi), loy(ylo);

    lcs_lens(xlo, xmid, ylo, yhi, ll_b);
    lcs_lens(hix, midx, hiy, loy, ll_e);

    // Find the optimal place to split the y range
    lengths::const_reverse_iterator e = ll_e.rbegin();
    int lmax = -1;
    it y = ylo, ymid = ylo;

    for (lengths::const_iterator b = ll_b.begin();
        b != ll_b.end(); ++y, ++b, ++e)
    {
      if (*b + *e > lmax)
      {
        lmax = *b + *e;
        ymid = y;
      }
    }
    // Split the range and recurse
    calculate_lcs(xo, xlo, xmid, ylo, ymid, xs_in_lcs);
    calculate_lcs(xo, xmid, xhi, ymid, yhi, xs_in_lcs);
  }
}
// Calculate an LCS of (xs, ys), returning the result in an_lcs. 
  template <typename seq>
void lcs(seq const & xs, seq const & ys, seq & an_lcs)
{
  members xs_in_lcs(xs.size(), false);
  calculate_lcs(xs.begin(), xs.begin(), xs.end(),
      ys.begin(), ys.end(), xs_in_lcs);
  set_lcs(xs.begin(), xs_in_lcs, back_inserter(an_lcs));
}


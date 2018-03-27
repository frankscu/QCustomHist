#ifndef TEMPLATE_HIST_HXX
#define TEMPLATE_HIST_HXX

#include <algorithm>
#include <limits>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stdexcept>
#include <map>

namespace Hist
{

  /*!
   * \em Dense Histogram of \p a.
   *
   * \tparam V is Value Type.
   * \tparam C is Count (Bin) Type.
   * \tparam H is Histogram Storage Type, typically a vector.
   *
   * \param[in] x is a set of the input data set
   */
  template <class V, class C = size_t, class H >
    inline void histogram_impl(const V & x, H& h) {
      typedef typename V::value_type E; // element type
      C bmax = 0;                      // bin max
      std::for_each(std::begin(x), std::end(x),  // C++11
                    [&h, &bmax] (const E & e) 
                    { // value element
                      h[e]++;
                      bmax = std::max(bmax, h[e]);
                      });
    }

  template <class V, class C = size_t, class H = std::vector<C> >
    inline H dense_histogram(const V & x) {
      typedef typename V::value_type E; // element type
      size_t n = (static_cast<C>(1)) << (8*sizeof(E)); // maximum number of possible elements for dense variant
      H h(n, 0);                       // histogram
      histogram_impl(x, h);
      return h;
    }

  /*!
   * \em Sparse Histogram of \p a.
   *
   * \tparam V is Value Type.
   * \tparam C is Count (Bin) Type.
   * \tparam H is Histogram Structure Type, typically a unordered_map.
   *
   * \param[in] x is a set of the input data set
   */
  template <class V, class C = size_t, class H = std::unordered_map<typename V::value_type, C> >
    inline H sparse_histogram(const V & x) {
      H h;                        // histogram
      histogram_impl(x, h);
      return h;
    }

}

#endif

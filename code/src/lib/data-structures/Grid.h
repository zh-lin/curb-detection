/******************************************************************************
 * Copyright (C) 2011 by Jerome Maye                                          *
 * jerome.maye@gmail.com                                                      *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the Lesser GNU General Public License as published by*
 * the Free Software Foundation; either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * Lesser GNU General Public License for more details.                        *
 *                                                                            *
 * You should have received a copy of the Lesser GNU General Public License   *
 * along with this program. If not, see <http://www.gnu.org/licenses/>.       *
 ******************************************************************************/

/** \file Grid.h
    \brief This file defines the Grid class, which represents an n-dimensional
           grid
  */

#ifndef GRID_H
#define GRID_H

#include "base/Serializable.h"
#include "exceptions/OutOfBoundException.h"
#include "exceptions/BadArgumentException.h"
#include "utils/SizeTSupport.h"

#include <vector>

/** The class Grid represents an n-dimensional grid.
    \brief An n-dimensional grid
  */
template <typename T, typename C, size_t M> class Grid :
  public virtual Serializable {
public:
  /** \name Types definitions
    @{
    */
  /// Container type
  typedef std::vector<C> Container;
  /// Constant iterator type
  typedef typename Container::const_iterator ConstCellIterator;
  /// Iterator type
  typedef typename Container::iterator CellIterator;
  /// Index type
  typedef Eigen::Matrix<size_t, M, 1> Index;
  /// Coordinate type
  typedef Eigen::Matrix<T, M, 1> Coordinate;
  /** @}
    */

  /** \name Constructors/destructor
    @{
    */
  /// Constructs grid with parameters
  Grid(const Coordinate& minimum, const Coordinate& maximum, const Coordinate&
    resolution) throw (BadArgumentException<Coordinate>);
  /// Copy constructor
  Grid(const Grid& other);
  /// Assignment operator
  Grid& operator = (const Grid& other);
  /// Destructor
  virtual ~Grid();
  /** @}
    */

  /** \name Accessors
      @{
    */
  /// Returns iterator at start of the container
  ConstCellIterator getCellBegin() const;
  /// Returns iterator at start of the container
  CellIterator getCellBegin();
  /// Returns iterator at end of the container
  ConstCellIterator getCellEnd() const;
  /// Returns iterator at end of the container
  CellIterator getCellEnd();
  /// Returns the container
  const Container& getCells() const;
  /// Returns the cell at index
  const C& getCell(const Index& idx) const throw (OutOfBoundException<Index>);
  /// Returns the cell at index
  C& getCell(const Index& idx) throw (OutOfBoundException<Index>);
  /// Returns a cell using [index] operator
  const C& operator [] (const Index& idx) const;
  /// Returns a cell using [index] operator
  C& operator [] (const Index& idx);
  /// Returns the index of a cell using coordinates
  Index getIndex(const Coordinate& point) const throw
    (OutOfBoundException<Coordinate>);
  /// Returns a cell using (coordinate) operator
  const C& operator () (const Coordinate& point) const;
  /// Returns a cell using (coordinate) operator
  C& operator () (const Coordinate& point);
  /// Returns the coordinates of a cell using index
  Coordinate getCoordinates(const Index& idx) const throw
    (OutOfBoundException<Index>);
  /// Check if the grid contains the point
  bool isInRange(const Coordinate& point) const;
  /// Check if an index is valid
  bool isValidIndex(const Index& idx) const;
  /// Returns the number of cells in each dimension
  const Index& getNumCells() const;
  /// Returns the total number of cells
  size_t getNumCellsTot() const;
  /// Returns the minimum of the grid
  const Coordinate& getMinimum() const;
  /// Returns the maximum of the grid
  const Coordinate& getMaximum() const;
  /// Returns the resolution of the grid
  const Coordinate& getResolution() const;
  /// Computes linear index
  size_t computeLinearIndex(const Index& idx) const;
  /// Reset the grid
  void reset();
  /** @}
    */

protected:
  /** \name Stream methods
    @{
    */
  /// Reads from standard input
  virtual void read(std::istream& stream);
  /// Writes to standard output
  virtual void write(std::ostream& stream) const;
  /// Reads from a file
  virtual void read(std::ifstream& stream);
  /// Writes to a file
  virtual void write(std::ofstream& stream) const;
  /** @}
    */

  /** \name Protected members
      @{
    */
  /// Cell container
  Container mCells;
  /// Minimum coordinate of the grid
  Coordinate mMinimum;
  /// Maximum coordinate of the grid
  Coordinate mMaximum;
  /// Resolution of the grid
  Coordinate mResolution;
  /// Number of cells in each dimension
  Index mNumCells;
  /// Total number of cells
  size_t mNumCellsTot;
  /// Pre-computation for linear indices
  Index mLinProd;
  /** @}
    */

};

#include "data-structures/Grid.tpp"

#endif // GRID_H
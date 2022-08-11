#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (v >= 0 && v < NumVerticalCells)
	{
		vCell = v;
		return true;
	}
	vCell = -1;
	return false;     // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (h >= 0 && h < NumHorizontalCells)
	{
		hCell = h;
		return true;
	}
	hCell = -1;
	return false; // this line sould be changed with your implementation
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	///TODO: Implement this function as described in the .h file
	if ((vCell >= 0 && vCell < NumVerticalCells) && (hCell >= 0 && hCell < NumHorizontalCells))
		return true;
	return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file
	if (cellPosition.IsValidCell())
	{
		int cellnum;
		cellnum = ((NumVerticalCells * NumHorizontalCells) - (NumHorizontalCells - 1)) - (NumHorizontalCells * cellPosition.vCell) + cellPosition.hCell;
		return cellnum; // this line should be changed with your implementation
	}
	return 0;
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	/// TODO: Implement this function as described in the .h file

	int j = 0; int vcell = -1, hcell = -1;
	for (int i = 1; i <= ((NumVerticalCells * NumHorizontalCells) - (NumHorizontalCells - 1)); i += NumHorizontalCells)
	{
		if (cellNum >= i && cellNum <= (i + (NumHorizontalCells - 1)))
		{
			vcell = (NumVerticalCells - 1) - j;
			hcell = cellNum - (((NumVerticalCells * NumHorizontalCells) - (NumHorizontalCells - 1)) - (NumHorizontalCells * vcell));
			break;
		}
		j++;
	}
	position.SetHCell(hcell);
	position.SetVCell(vcell);
	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it
	return position;
}

void CellPosition::AddCellNum (int addedNum)
{
	
	/// TODO: Implement this function as described in the .h file

	int num = GetCellNum() + addedNum;
	(*this)=GetCellPositionFromNum(num);

	// Note: this function updates the data members (vCell and hCell) of the calling object

}
#ifndef COMMON_DEFINITION_H
#define	COMMON_DEFINITION_H

const int FIELD_HEIGHT = 25;
const int FIELD_WIDTH = 14;

const int STAGE_WIDTH = 10;

const int BLOCK_HEIGHT = 14;
const int BLOCK_WIDTH = 14;

const int MINO_HEIGHT = 4;
const int MINO_WIDTH = 4;

enum class BlockType
{
	I,
	O,
	S,
	Z,
	J,
	L,
	T,
	Stage,
	Wall,
	Empty,
};

#endif
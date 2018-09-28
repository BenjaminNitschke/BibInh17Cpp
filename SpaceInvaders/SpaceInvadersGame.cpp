#include "stdafx.h"
#include "SpaceInvadersGame.h"
#include "png.h"

int x, y;
int width, height;
png_byte color_type;
png_byte bit_depth;
png_structp png_ptr;
png_infop info_ptr;
int number_of_passes;
png_bytep * row_pointers;

void read_png_file(const char* file_name)
{
	char header[8];
	FILE *fp;
	fopen_s(&fp, file_name, "rb");
	if (!fp)
		throw "[read_png_file] File %s could not be opened for reading";
	fread(header, 1, 8, fp);
	if (png_sig_cmp((png_bytep)header, 0, 8))
		throw "[read_png_file] File %s is not recognized as a PNG file";


	// initialize stuff
	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

	if (!png_ptr)
		throw "[read_png_file] png_create_read_struct failed";

	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr)
		throw "[read_png_file] png_create_info_struct failed";

	if (setjmp(png_jmpbuf(png_ptr)))
		throw "[read_png_file] Error during init_io";

	png_init_io(png_ptr, fp);
	png_set_sig_bytes(png_ptr, 8);

	png_read_info(png_ptr, info_ptr);

	width = png_get_image_width(png_ptr, info_ptr);
	height = png_get_image_height(png_ptr, info_ptr);
	color_type = png_get_color_type(png_ptr, info_ptr);
	bit_depth = png_get_bit_depth(png_ptr, info_ptr);

	number_of_passes = png_set_interlace_handling(png_ptr);
	png_read_update_info(png_ptr, info_ptr);


	// read file
	if (setjmp(png_jmpbuf(png_ptr)))
		throw "[read_png_file] Error during read_image";

	row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * height);
	for (y = 0; y<height; y++)
		row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png_ptr, info_ptr));

	png_read_image(png_ptr, row_pointers);

	fclose(fp);
}

SpaceInvadersGame::SpaceInvadersGame()
{
	//load textures..
	read_png_file("test.png");

}


SpaceInvadersGame::~SpaceInvadersGame()
{
}
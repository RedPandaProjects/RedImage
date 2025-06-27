// TestApp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "..\RedImageTool\RedImage.hpp"

int main()
{
    using namespace RedImageTool;

    RedImage Test;

    if (!Test.LoadFromFile("test.png"))
    {
        printf("Failed to load input image\n");
        return 1;
    }

    Test.GenerateMipmap(RedResizeFilter::Box);

    Test.Convert(RedTexturePixelFormat::BC7);
    if (!Test.SaveToDds("test.dds"))
    {
        printf("Failed to save DDS\n");
        return 1;
    }

    Test.Convert(RedTexturePixelFormat::R8G8B8A8);
    if (!Test.SaveToTga("test.tga"))
    {
        printf("Failed to save TGA\n");
        return 1;
    }

    // Сохраняем JPEG в память
    constexpr size_t jpeg_buffer_capacity = 1024 * 1024; // 1MB буфер
    u8* jpeg_buffer = new u8[jpeg_buffer_capacity];
    size_t jpeg_size = 0;

    if (Test.SaveToJpgMemory(jpeg_buffer, jpeg_buffer_capacity, jpeg_size, 75))
    {
        printf("JPEG saved to memory: %zu bytes\n", jpeg_size);

        // Например, можно сохранить его из памяти на диск для проверки
        FILE* f = fopen("test_memory.jpg", "wb");
        if (f)
        {
            fwrite(jpeg_buffer, 1, jpeg_size, f);
            fclose(f);
            printf("Saved JPEG from memory to 'test_memory.jpg'\n");
        }
    }
    else
    {
        printf("Failed to save JPEG to memory\n");
    }

    delete[] jpeg_buffer;

    return 0;
}
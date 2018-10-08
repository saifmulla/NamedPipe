#include <Windows.h>
#include <memory>

TEST(TestCreateFile, create_named_pipe) {
	HANDLE pipe_handle = nullptr;
	pipe_handle = CreateNamedPipe(TEXT("\\\\.\\pipe\\Pipe"),
		PIPE_ACCESS_DUPLEX,
		PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,   // FILE_FLAG_FIRST_PIPE_INSTANCE is not needed but forces CreateNamedPipe(..) to fail if the pipe already exists...
		1,
		1024 * 16,
		1024 * 16,
		NMPWAIT_USE_DEFAULT_WAIT,
		NULL);
	if (pipe_handle != nullptr)
		ASSERT_TRUE(true);
	else
		ASSERT_FALSE(false);


}
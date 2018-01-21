<<<<<<< HEAD
#include "Cheat.h"
#include <TlHelp32.h>

cSecurity* Security;


typedef struct _UNICODE_STRING
{
	USHORT Length;
	USHORT MaximumLength;
	PWSTR Buffer;
} UNICODE_STRING, *PUNICODE_STRING;

typedef struct _LDR_MODULE_DUMMY_
{
	LIST_ENTRY InLoadOrderModuleList;
	LIST_ENTRY InMemoryOrderModuleList;
	LIST_ENTRY InInitializationOrderModuleList;
	PVOID BaseAddress;

	PVOID EntryPoint;
	ULONG SizeOfImage;
	UNICODE_STRING FullDllName;
	UNICODE_STRING BaseDllName;
	ULONG Flags;
	SHORT LoadCount;
	SHORT TlsIndex;
	LIST_ENTRY HashTableEntry;
	ULONG TimeDateStamp;
} LDR_MODULE, *PLDR_MODULE;

typedef struct _PEB_LDR_DATA_DUMMY_
{
	ULONG Length;
	UCHAR Initialized;
	PVOID SsHandle;
	LIST_ENTRY InLoadOrderModuleList;
	LIST_ENTRY InMemoryOrderModuleList;
	LIST_ENTRY InInitializationOrderModuleList;
	PVOID EntryInProgress;
} PEB_LDR_DATA, *PPEB_LDR_DATA;

typedef struct PEB_DUMMY_
{
	PVOID Dummy1;
	PVOID Dummy2;
	PVOID Dummy3;
	PPEB_LDR_DATA LDR_Data;
} PEB_DUMMY, *PPEB_DUMMY;

typedef struct _CLIENT_ID
{
	HANDLE UniqueProcess;
	HANDLE UniqueThread;
} CLIENT_ID, *PCLIENT_ID;

typedef struct _RTL_DRIVE_LETTER_CURDIR
{
	USHORT Flags;
	USHORT Length;
	ULONG TimeStamp;
	UNICODE_STRING DosPath;
} RTL_DRIVE_LETTER_CURDIR, *PRTL_DRIVE_LETTER_CURDIR;

typedef struct _RTL_USER_PROCESS_PARAMETERS
{
	ULONG MaximumLength;
	ULONG Length;
	ULONG Flags;
	ULONG DebugFlags;
	PVOID ConsoleHandle;
	ULONG ConsoleFlags;
	HANDLE StdInputHandle;
	HANDLE StdOutputHandle;
	HANDLE StdErrorHandle;
	UNICODE_STRING CurrentDirectoryPath;
	HANDLE CurrentDirectoryHandle;
	UNICODE_STRING DllPath;
	UNICODE_STRING ImagePathName;
	UNICODE_STRING CommandLine;
	PVOID Environment;
	ULONG StartingPositionLeft;
	ULONG StartingPositionTop;
	ULONG Width;
	ULONG Height;
	ULONG CharWidth;
	ULONG CharHeight;
	ULONG ConsoleTextAttributes;
	ULONG WindowFlags;
	ULONG ShowWindowFlags;
	UNICODE_STRING WindowTitle;
	UNICODE_STRING DesktopName;
	UNICODE_STRING ShellInfo;
	UNICODE_STRING RuntimeData;
	RTL_DRIVE_LETTER_CURDIR DLCurrentDirectory[0x20];
} RTL_USER_PROCESS_PARAMETERS, *PRTL_USER_PROCESS_PARAMETERS;

typedef void(*PPEBLOCKROUTINE)(PVOID PebLock);

typedef struct _PEB_FREE_BLOCK
{
	_PEB_FREE_BLOCK* Next;
	DWORD Size;
} PEB_FREE_BLOCK, *PPEB_FREE_BLOCK;

typedef struct _PEB
{
	BOOLEAN InheritedAddressSpace;
	BOOLEAN ReadImageFileExecOptions;
	BOOLEAN BeingDebugged;
	BOOLEAN Spare;
	HANDLE Mutant;
	PVOID ImageBaseAddress;
	PPEB_LDR_DATA LoaderData;
	PRTL_USER_PROCESS_PARAMETERS ProcessParameters;
	PVOID SubSystemData;
	PVOID ProcessHeap;
	PVOID FastPebLock;
	PPEBLOCKROUTINE FastPebLockRoutine;
	PPEBLOCKROUTINE FastPebUnlockRoutine;
	ULONG EnvironmentUpdateCount;
	PVOID* KernelCallbackTable;
	PVOID EventLogSection;
	PVOID EventLog;
	PPEB_FREE_BLOCK FreeList;
	ULONG TlsExpansionCounter;
	PVOID TlsBitmap;
	ULONG TlsBitmapBits[0x2];
	PVOID ReadOnlySharedMemoryBase;
	PVOID ReadOnlySharedMemoryHeap;
	PVOID* ReadOnlyStaticServerData;
	PVOID AnsiCodePageData;
	PVOID OemCodePageData;
	PVOID UnicodeCaseTableData;
	ULONG NumberOfProcessors;
	ULONG NtGlobalFlag;
	BYTE Spare2[0x4];
	LARGE_INTEGER CriticalSectionTimeout;
	ULONG HeapSegmentReserve;
	ULONG HeapSegmentCommit;
	ULONG HeapDeCommitTotalFreeThreshold;
	ULONG HeapDeCommitFreeBlockThreshold;
	ULONG NumberOfHeaps;
	ULONG MaximumNumberOfHeaps;
	PVOID** ProcessHeaps;
	PVOID GdiSharedHandleTable;
	PVOID ProcessStarterHelper;
	PVOID GdiDCAttributeList;
	PVOID LoaderLock;
	ULONG OSMajorVersion;
	ULONG OSMinorVersion;
	ULONG OSBuildNumber;
	ULONG OSPlatformId;
	ULONG ImageSubSystem;
	ULONG ImageSubSystemMajorVersion;
	ULONG ImageSubSystemMinorVersion;
	ULONG GdiHandleBuffer[0x22];
	ULONG PostProcessInitRoutine;
	ULONG TlsExpansionBitmap;
	BYTE TlsExpansionBitmapBits[0x80];
	ULONG SessionId;
} PEB, *PPEB;

typedef struct _TEB
{
	NT_TIB Tib;
	PVOID EnvironmentPointer;
	CLIENT_ID Cid;
	PVOID ActiveRpcInfo;
	PVOID ThreadLocalStoragePointer;
	PPEB Peb;
	ULONG LastErrorValue;
	ULONG CountOfOwnedCriticalSections;
	PVOID CsrClientThread;
	PVOID Win32ThreadInfo;
	ULONG Win32ClientInfo[0x1F];
	PVOID WOW32Reserved;
	ULONG CurrentLocale;
	ULONG FpSoftwareStatusRegister;
	PVOID SystemReserved1[0x36];
	PVOID Spare1;
	ULONG ExceptionCode;
	ULONG SpareBytes1[0x28];
	PVOID SystemReserved2[0xA];
	ULONG GdiRgn;
	ULONG GdiPen;
	ULONG GdiBrush;
	CLIENT_ID RealClientId;
	PVOID GdiCachedProcessHandle;
	ULONG GdiClientPID;
	ULONG GdiClientTID;
	PVOID GdiThreadLocaleInfo;
	PVOID UserReserved[5];
	PVOID GlDispatchTable[0x118];
	ULONG GlReserved1[0x1A];
	PVOID GlReserved2;
	PVOID GlSectionInfo;
	PVOID GlSection;
	PVOID GlTable;
	PVOID GlCurrentRC;
	PVOID GlContext;
	NTSTATUS LastStatusValue;
	UNICODE_STRING StaticUnicodeString;
	WCHAR StaticUnicodeBuffer[0x105];
	PVOID DeallocationStack;
	PVOID TlsSlots[0x40];
	LIST_ENTRY TlsLinks;
	PVOID Vdm;
	PVOID ReservedForNtRpc;
	PVOID DbgSsReserved[0x2];
	ULONG HardErrorDisabled;
	PVOID Instrumentation[0x10];
	PVOID WinSockData;
	ULONG GdiBatchCount;
	ULONG Spare2;
	ULONG Spare3;
	ULONG Spare4;
	PVOID ReservedForOle;
	ULONG WaitingOnLoaderLock;
	PVOID StackCommit;
	PVOID StackCommitMax;
	PVOID StackReserved;
} TEB, *PTEB;


 bool Int2DCheck()
{
	__try
	{
		__asm
		{
			int 0x2d
			xor eax, eax
			add eax, 2
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return false;
	}

	return true;
}

 bool IsDbgPresentPrefixCheck()
{
	__try
	{
		__asm __emit 0xF3 // 0xF3 0x64 disassembles as PREFIX REP:
		__asm __emit 0x64
		__asm __emit 0xF1 // One byte INT 1
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return false;
	}

	return true;
}

bool checkGlobalFlags()
{
	DWORD NtGlobalFlags;
	__asm
	{
		mov eax, fs:[30h]
		mov eax, [eax + 68h]
		mov NtGlobalFlags, eax
	}

	if (NtGlobalFlags & 0x70)
		return true;

	return false;
}

DWORD GetProcessIdByName(LPCTSTR name)
{
	PROCESSENTRY32 pe32;
	HANDLE snapshot = NULL;
	DWORD pid = 0;

	snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snapshot != INVALID_HANDLE_VALUE) {
		pe32.dwSize = sizeof(PROCESSENTRY32);

		if (Process32First(snapshot, &pe32)) {
			do {
				std::string sName = pe32.szExeFile;
				std::transform(sName.begin(), sName.end(), sName.begin(), ::tolower);

				if (!lstrcmp(sName.c_str(), name)) {
					pid = pe32.th32ProcessID;
					break;
				}
			} while (Process32Next(snapshot, &pe32));
		}

		CloseHandle(snapshot);
	}

	return pid;
}

void cSecurity::CheckAllPorcesses()
{
	std::vector<std::string> m_processList;
	m_processList.push_back(charenc("ollydbg.exe"));
	m_processList.push_back(charenc("wireshark.exe"));
	m_processList.push_back(charenc("lordpe.exe"));
	m_processList.push_back(charenc("hookshark.exe"));
	m_processList.push_back(charenc("idag.exe"));
	m_processList.push_back(charenc("MPGH Virus Scan Tool v6.exe"));

	for (unsigned int ax = 0; ax < m_processList.size(); ax++)
	{
		std::string sProcess = m_processList.at(ax);
		if (GetProcessIdByName(sProcess.c_str()) != 0)
		{
			exit(0);
		}
	}
}

inline uint16_t getCpuHash()
{
	int cpuinfo[4] = { 0, 0, 0, 0 };
	__cpuid(cpuinfo, 0);
	uint16_t hash = 0;
	auto ptr = reinterpret_cast<uint16_t*>(&cpuinfo[0]);
	for (auto i = 0; i < 10; i++)
		hash += ptr[i];
	return hash;
}

uint16_t GetHWID()
{
	static char computerName[1024];
	DWORD size = 1024;
	GetComputerName(computerName, &size);

	DWORD serialNum = 0;
	GetVolumeInformation(("c:\\"), nullptr, 0, &serialNum, nullptr, nullptr, nullptr, 0);
	auto hash = static_cast<uint16_t>((serialNum + (serialNum >> 86)) & 0xFFFF);
	hash = hash + static_cast<uint16_t>(((int)computerName[0] + ((int)computerName[0] >> 26)) & 0xFFFF);

	return (hash / 2 * 15 * (768 % 678));
}



inline BOOL CanOpenCsrss()
{
	HANDLE hCsrss = 0;

	hCsrss = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetProcessIdByName(charenc("csrss.exe")));

	if (hCsrss != NULL)
	{
		CloseHandle(hCsrss);
		return TRUE;
	}
	else
		return FALSE;

}


PPEB_DUMMY __declspec(naked) GetPEB(void)
{
	_asm
	{
		mov eax, fs:[0x30];
		retn;
	}
}

DWORD cSecurity::HideMod(HMODULE mod)
{
	DWORD MBA;
	DWORD MBS;
	PTEB pTEB;
	PPEB_LDR_DATA pLDR;
	PLIST_ENTRY pM, pCM;
	PLDR_MODULE pMM;
	int M = 0, L = 0, I = 0, temp = 0;
	IMAGE_DOS_HEADER *DOSH = (IMAGE_DOS_HEADER*)mod;
	IMAGE_NT_HEADERS *NTH = NULL;
	DWORD OP;
	__asm
	{
		xor eax, eax;
		mov eax, fs:[0x18];
		mov pTEB, eax;
	}
	pLDR = pTEB->Peb->LoaderData;
	if (DOSH->e_magic != IMAGE_DOS_SIGNATURE) return 0;
	NTH = ((PIMAGE_NT_HEADERS)((DWORD)(DOSH)+(DWORD)(DOSH->e_lfanew)));
	if (NTH->Signature != IMAGE_NT_SIGNATURE) return 0;
	MBS = NTH->OptionalHeader.SizeOfImage;
	MBA = NTH->OptionalHeader.ImageBase;

	if (!pLDR) return 1;
	for (int m = 0; m <= 2; m++)
	{
		if (m == 0) pM = &(pLDR->InMemoryOrderModuleList);
		if (m == 1) pM = &(pLDR->InLoadOrderModuleList);
		if (m == 2) pM = &(pLDR->InInitializationOrderModuleList);
		for (pCM = pM->Flink; pCM != pM; pCM = pCM->Flink)
		{
			if (m == 0) pMM = CONTAINING_RECORD(pCM, LDR_MODULE, InMemoryOrderModuleList);
			if (m == 1) pMM = CONTAINING_RECORD(pCM, LDR_MODULE, InLoadOrderModuleList);
			if (m == 2) pMM = CONTAINING_RECORD(pCM, LDR_MODULE, InInitializationOrderModuleList);
			if ((DWORD)pMM->BaseAddress == MBA && (DWORD)pMM->SizeOfImage == MBS)
			{
				pCM->Blink->Flink = pCM->Flink;
				pCM->Flink->Blink = pCM->Blink;
			}
		}
	}
	VirtualProtect((LPVOID)DOSH, NTH->OptionalHeader.SizeOfHeaders, PAGE_EXECUTE_READWRITE, &OP);
	memset((LPVOID)DOSH, 0, NTH->OptionalHeader.SizeOfHeaders);
	VirtualProtect((LPVOID)DOSH, NTH->OptionalHeader.SizeOfHeaders, OP, &OP);
	return 3;
}


void cSecurity::HideModuleFromPEB(HINSTANCE hInstance)
{
	PPEB_DUMMY PEB = GetPEB();

	PLIST_ENTRY FirstEntryInLoadOrder = (PLIST_ENTRY)&PEB->LDR_Data->InLoadOrderModuleList;
	PLIST_ENTRY FirstEntryInMemoryOrder = (PLIST_ENTRY)&PEB->LDR_Data->InMemoryOrderModuleList;
	PLIST_ENTRY FirstEntryInInitOrder = (PLIST_ENTRY)&PEB->LDR_Data->InInitializationOrderModuleList;

	for (PLIST_ENTRY TempEntry = FirstEntryInLoadOrder->Flink; TempEntry != FirstEntryInLoadOrder; TempEntry = TempEntry->Flink)
	{
		PLDR_MODULE TempModule = (PLDR_MODULE)((DWORD)TempEntry - 0 * sizeof(LIST_ENTRY));
		if (TempModule->BaseAddress == hInstance)
		{
			TempEntry->Blink->Flink = TempEntry->Flink;
			TempEntry->Flink->Blink = TempEntry->Blink;
			break;
		}
	}

	for (PLIST_ENTRY TempEntry = FirstEntryInMemoryOrder->Flink; TempEntry != FirstEntryInMemoryOrder; TempEntry = TempEntry->Flink)
	{
		PLDR_MODULE TempModule = (PLDR_MODULE)((DWORD)TempEntry - 1 * sizeof(LIST_ENTRY));
		if (TempModule->BaseAddress == hInstance)
		{
			TempEntry->Blink->Flink = TempEntry->Flink;
			TempEntry->Flink->Blink = TempEntry->Blink;
			break;
		}
	}

	for (PLIST_ENTRY TempEntry = FirstEntryInInitOrder->Flink; TempEntry != FirstEntryInInitOrder; TempEntry = TempEntry->Flink)
	{
		PLDR_MODULE TempModule = (PLDR_MODULE)((DWORD)TempEntry - 2 * sizeof(LIST_ENTRY));
		if (TempModule->BaseAddress == hInstance)
		{
			TempEntry->Blink->Flink = TempEntry->Flink;
			TempEntry->Flink->Blink = TempEntry->Blink;
			break;
		}
	}
}
void cSecurity::RemovePeHeader(DWORD ModuleBase)
{
	PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)ModuleBase;
	PIMAGE_NT_HEADERS pNTHeader = (PIMAGE_NT_HEADERS)((DWORD)pDosHeader + (DWORD)pDosHeader->e_lfanew);

	if (pNTHeader->Signature != IMAGE_NT_SIGNATURE)
		return;

	if (pNTHeader->FileHeader.SizeOfOptionalHeader)
	{
		DWORD Protect;
		WORD Size = pNTHeader->FileHeader.SizeOfOptionalHeader;
		VirtualProtect((void*)ModuleBase, Size, PAGE_EXECUTE_READWRITE, &Protect);
		RtlZeroMemory((void*)ModuleBase, Size);
		VirtualProtect((void*)ModuleBase, Size, Protect, &Protect);
	}
}
void cSecurity::HideModule(HANDLE hModule)
{
	PIMAGE_DOS_HEADER pDOSHeader = (PIMAGE_DOS_HEADER)hModule;
	if (pDOSHeader->e_magic == IMAGE_DOS_SIGNATURE)
	{
		PIMAGE_NT_HEADERS pNTHeader = (PIMAGE_NT_HEADERS)((DWORD)pDOSHeader + (DWORD)pDOSHeader->e_lfanew);
		if (pNTHeader->Signature == IMAGE_NT_SIGNATURE)
		{
			DWORD dwOld, dwSize = pNTHeader->OptionalHeader.SizeOfHeaders;
			if (VirtualProtect((LPVOID)pDOSHeader, dwSize, PAGE_READWRITE, &dwOld))
			{
				memset((void*)pDOSHeader, 0, dwSize);
				VirtualProtect((LPVOID)pDOSHeader, dwSize, dwOld, &dwOld);
			}
		}
		_TEB *pTeb = nullptr;
		_asm
		{
			mov eax, fs:[0x18]
			mov pTeb, eax
		}
		PLIST_ENTRY pList = &pTeb->Peb->LoaderData->InLoadOrderModuleList;
		for (PLIST_ENTRY pEntry = pList->Flink; pEntry != pList; pEntry = pEntry->Flink)
		{
			PLDR_MODULE pModule = (PLDR_MODULE)pEntry;
			if (pModule->BaseAddress == hModule)
			{
				pEntry = &pModule->InLoadOrderModuleList; pEntry->Blink->Flink = pEntry->Flink; pEntry->Flink->Blink = pEntry->Blink;
				memset(pEntry, 0, sizeof(LIST_ENTRY));
				pEntry = &pModule->InMemoryOrderModuleList; pEntry->Blink->Flink = pEntry->Flink; pEntry->Flink->Blink = pEntry->Blink;
				memset(pEntry, 0, sizeof(LIST_ENTRY));
				pEntry = &pModule->InInitializationOrderModuleList; pEntry->Blink->Flink = pEntry->Flink; pEntry->Flink->Blink = pEntry->Blink;
				memset(pEntry, 0, sizeof(LIST_ENTRY));
				pEntry = &pModule->HashTableEntry; pEntry->Blink->Flink = pEntry->Flink; pEntry->Flink->Blink = pEntry->Blink;
				memset(pEntry, 0, sizeof(LIST_ENTRY));
				memset(pModule->FullDllName.Buffer, 0, pModule->FullDllName.Length);
				memset(pModule, 0, sizeof(LDR_MODULE));
				break;
			}
		}
	}
}
void cSecurity::HideModuleXta(HINSTANCE hModule)
{
	DWORD dwPEB_LDR_DATA = 0;

	_asm
	{
		pushad;
		pushfd;
		mov eax, fs:[30h]
			mov eax, [eax + 0Ch]
			mov dwPEB_LDR_DATA, eax
			mov esi, [eax + 0Ch]
			mov edx, [eax + 10h]

			LoopInLoadOrderModuleList :
			lodsd
			mov esi, eax
			mov ecx, [eax + 18h]
			cmp ecx, hModule
			jne SkipA
			mov ebx, [eax]
			mov ecx, [eax + 4]
			mov[ecx], ebx
			mov[ebx + 4], ecx
			jmp InMemoryOrderModuleList
			SkipA :
		cmp edx, esi
			jne LoopInLoadOrderModuleList

			InMemoryOrderModuleList :
		mov eax, dwPEB_LDR_DATA
			mov esi, [eax + 14h]
			mov edx, [eax + 18h]

			LoopInMemoryOrderModuleList :
			lodsd
			mov esi, eax
			mov ecx, [eax + 10h]
			cmp ecx, hModule
			jne SkipB
			mov ebx, [eax]
			mov ecx, [eax + 4]
			mov[ecx], ebx
			mov[ebx + 4], ecx
			jmp InInitializationOrderModuleList
			SkipB :
		cmp edx, esi
			jne LoopInMemoryOrderModuleList

			InInitializationOrderModuleList :
		mov eax, dwPEB_LDR_DATA
			mov esi, [eax + 1Ch]
			mov edx, [eax + 20h]

			LoopInInitializationOrderModuleList :
			lodsd
			mov esi, eax
			mov ecx, [eax + 08h]
			cmp ecx, hModule
			jne SkipC
			mov ebx, [eax]
			mov ecx, [eax + 4]
			mov[ecx], ebx
			mov[ebx + 4], ecx
			jmp Finished
			SkipC :
		cmp edx, esi
			jne LoopInInitializationOrderModuleList

			Finished :
		popfd;
		popad;
	}
}
bool cSecurity::DestroyModuleHeader(HMODULE hModule)
{
	DWORD dwStartOffset = (DWORD)hModule;

	IMAGE_DOS_HEADER *pDosHeader = (PIMAGE_DOS_HEADER)dwStartOffset;
	if (pDosHeader->e_magic != IMAGE_DOS_SIGNATURE)
		return false;

	IMAGE_NT_HEADERS *pNtHeader = (PIMAGE_NT_HEADERS)(dwStartOffset + pDosHeader->e_lfanew);
	if (pNtHeader->Signature != IMAGE_NT_SIGNATURE)
		return false;

	DWORD dwOldProtection = NULL;
	if (!VirtualProtect((PVOID)hModule, pNtHeader->OptionalHeader.SizeOfHeaders, PAGE_EXECUTE_READWRITE, &dwOldProtection))
		return false;

	ZeroMemory((PVOID)hModule, pNtHeader->OptionalHeader.SizeOfHeaders);
	VirtualProtect((PVOID)hModule, pNtHeader->OptionalHeader.SizeOfHeaders, dwOldProtection, &dwOldProtection);

	return true;
}

int HWIDS[] =
{
	38400,//Ich
	52824,//S4itama
	41688,//Luda
	18878,//Hazey
	25916,//jan
    52066,//Vane88
	54954,//peer
    39892,//mike
	31126,//zx8p
	45954,//crypto
	37064,//onurb,
	11780,//Avalanche
	24084,//danny
	53958,//muentzee
	58144,//xBlood
	52270,//nina und jule
	21272,//steven
	35698,//Toaster
	1122,//Zimty
	25498,//diego
	63892,//bilo
	38998,//SD
	34462,//nicolas
	14848,//tobi
	34112,//N4ffit
	55118,//Mike austria guy
	21018,//klausi invitd by toasty 1 monat starting 14.11
	4064,//jaffa 1 month starting 25.11
	8736,//justus 1 month starting 28.11
	48424,//Pr1x 1 month starting 11.11
	42812,//Rat 1 month Starting 30.11
	26982,//jay 1 month starting 30.11
	//53628,//bujasm 1 month Starting 25.11  NEED TO PAY!!! 1 descember
	40694,//lit/john 1 month Starting 10.12
	55226,//tecc  1 month starting 10.12
	41570//Casper420 1 month starting 10.12



};

void cSecurity::Check()
{
	VMProtectBeginUltra("chek");

	if (Int2DCheck())
		exit(0);

	if (IsDbgPresentPrefixCheck())
		exit(0);

	if (checkGlobalFlags())
		exit(0);

	time_t now = time(0);
	tm *ltm = localtime(&now);

	if (1900 + ltm->tm_year != 2017 || (1 + ltm->tm_mon) > 12 || (1 + ltm->tm_mday) > 24)  //subs
	{
		MessageBox(0, VMProtectDecryptStringA("Subscription Over, please Contact Ferrity"), VMProtectDecryptStringA("FH4x"), MB_OK);
		exit(0);
	}


	uint16_t curHWID = GetHWID();

	bool ok = false;

	for (int i = 0; i < ARRAYSIZE(HWIDS); i++)
	{
		if (curHWID == HWIDS[i])
		{
			ok = true;
			break;
		}
	}

	if (ok == false)
	{
		MessageBox(0, VMProtectDecryptStringA("Wrong HWID, please Contact Ferrity"), VMProtectDecryptStringA("FH4x"), MB_OK);
		exit(0);
	}

	VMProtectEnd();
}
=======
#include "Cheat.h"
#include <TlHelp32.h>

cSecurity* Security;


typedef struct _UNICODE_STRING
{
	USHORT Length;
	USHORT MaximumLength;
	PWSTR Buffer;
} UNICODE_STRING, *PUNICODE_STRING;

typedef struct _LDR_MODULE_DUMMY_
{
	LIST_ENTRY InLoadOrderModuleList;
	LIST_ENTRY InMemoryOrderModuleList;
	LIST_ENTRY InInitializationOrderModuleList;
	PVOID BaseAddress;

	PVOID EntryPoint;
	ULONG SizeOfImage;
	UNICODE_STRING FullDllName;
	UNICODE_STRING BaseDllName;
	ULONG Flags;
	SHORT LoadCount;
	SHORT TlsIndex;
	LIST_ENTRY HashTableEntry;
	ULONG TimeDateStamp;
} LDR_MODULE, *PLDR_MODULE;

typedef struct _PEB_LDR_DATA_DUMMY_
{
	ULONG Length;
	UCHAR Initialized;
	PVOID SsHandle;
	LIST_ENTRY InLoadOrderModuleList;
	LIST_ENTRY InMemoryOrderModuleList;
	LIST_ENTRY InInitializationOrderModuleList;
	PVOID EntryInProgress;
} PEB_LDR_DATA, *PPEB_LDR_DATA;

typedef struct PEB_DUMMY_
{
	PVOID Dummy1;
	PVOID Dummy2;
	PVOID Dummy3;
	PPEB_LDR_DATA LDR_Data;
} PEB_DUMMY, *PPEB_DUMMY;

typedef struct _CLIENT_ID
{
	HANDLE UniqueProcess;
	HANDLE UniqueThread;
} CLIENT_ID, *PCLIENT_ID;

typedef struct _RTL_DRIVE_LETTER_CURDIR
{
	USHORT Flags;
	USHORT Length;
	ULONG TimeStamp;
	UNICODE_STRING DosPath;
} RTL_DRIVE_LETTER_CURDIR, *PRTL_DRIVE_LETTER_CURDIR;

typedef struct _RTL_USER_PROCESS_PARAMETERS
{
	ULONG MaximumLength;
	ULONG Length;
	ULONG Flags;
	ULONG DebugFlags;
	PVOID ConsoleHandle;
	ULONG ConsoleFlags;
	HANDLE StdInputHandle;
	HANDLE StdOutputHandle;
	HANDLE StdErrorHandle;
	UNICODE_STRING CurrentDirectoryPath;
	HANDLE CurrentDirectoryHandle;
	UNICODE_STRING DllPath;
	UNICODE_STRING ImagePathName;
	UNICODE_STRING CommandLine;
	PVOID Environment;
	ULONG StartingPositionLeft;
	ULONG StartingPositionTop;
	ULONG Width;
	ULONG Height;
	ULONG CharWidth;
	ULONG CharHeight;
	ULONG ConsoleTextAttributes;
	ULONG WindowFlags;
	ULONG ShowWindowFlags;
	UNICODE_STRING WindowTitle;
	UNICODE_STRING DesktopName;
	UNICODE_STRING ShellInfo;
	UNICODE_STRING RuntimeData;
	RTL_DRIVE_LETTER_CURDIR DLCurrentDirectory[0x20];
} RTL_USER_PROCESS_PARAMETERS, *PRTL_USER_PROCESS_PARAMETERS;

typedef void(*PPEBLOCKROUTINE)(PVOID PebLock);

typedef struct _PEB_FREE_BLOCK
{
	_PEB_FREE_BLOCK* Next;
	DWORD Size;
} PEB_FREE_BLOCK, *PPEB_FREE_BLOCK;

typedef struct _PEB
{
	BOOLEAN InheritedAddressSpace;
	BOOLEAN ReadImageFileExecOptions;
	BOOLEAN BeingDebugged;
	BOOLEAN Spare;
	HANDLE Mutant;
	PVOID ImageBaseAddress;
	PPEB_LDR_DATA LoaderData;
	PRTL_USER_PROCESS_PARAMETERS ProcessParameters;
	PVOID SubSystemData;
	PVOID ProcessHeap;
	PVOID FastPebLock;
	PPEBLOCKROUTINE FastPebLockRoutine;
	PPEBLOCKROUTINE FastPebUnlockRoutine;
	ULONG EnvironmentUpdateCount;
	PVOID* KernelCallbackTable;
	PVOID EventLogSection;
	PVOID EventLog;
	PPEB_FREE_BLOCK FreeList;
	ULONG TlsExpansionCounter;
	PVOID TlsBitmap;
	ULONG TlsBitmapBits[0x2];
	PVOID ReadOnlySharedMemoryBase;
	PVOID ReadOnlySharedMemoryHeap;
	PVOID* ReadOnlyStaticServerData;
	PVOID AnsiCodePageData;
	PVOID OemCodePageData;
	PVOID UnicodeCaseTableData;
	ULONG NumberOfProcessors;
	ULONG NtGlobalFlag;
	BYTE Spare2[0x4];
	LARGE_INTEGER CriticalSectionTimeout;
	ULONG HeapSegmentReserve;
	ULONG HeapSegmentCommit;
	ULONG HeapDeCommitTotalFreeThreshold;
	ULONG HeapDeCommitFreeBlockThreshold;
	ULONG NumberOfHeaps;
	ULONG MaximumNumberOfHeaps;
	PVOID** ProcessHeaps;
	PVOID GdiSharedHandleTable;
	PVOID ProcessStarterHelper;
	PVOID GdiDCAttributeList;
	PVOID LoaderLock;
	ULONG OSMajorVersion;
	ULONG OSMinorVersion;
	ULONG OSBuildNumber;
	ULONG OSPlatformId;
	ULONG ImageSubSystem;
	ULONG ImageSubSystemMajorVersion;
	ULONG ImageSubSystemMinorVersion;
	ULONG GdiHandleBuffer[0x22];
	ULONG PostProcessInitRoutine;
	ULONG TlsExpansionBitmap;
	BYTE TlsExpansionBitmapBits[0x80];
	ULONG SessionId;
} PEB, *PPEB;

typedef struct _TEB
{
	NT_TIB Tib;
	PVOID EnvironmentPointer;
	CLIENT_ID Cid;
	PVOID ActiveRpcInfo;
	PVOID ThreadLocalStoragePointer;
	PPEB Peb;
	ULONG LastErrorValue;
	ULONG CountOfOwnedCriticalSections;
	PVOID CsrClientThread;
	PVOID Win32ThreadInfo;
	ULONG Win32ClientInfo[0x1F];
	PVOID WOW32Reserved;
	ULONG CurrentLocale;
	ULONG FpSoftwareStatusRegister;
	PVOID SystemReserved1[0x36];
	PVOID Spare1;
	ULONG ExceptionCode;
	ULONG SpareBytes1[0x28];
	PVOID SystemReserved2[0xA];
	ULONG GdiRgn;
	ULONG GdiPen;
	ULONG GdiBrush;
	CLIENT_ID RealClientId;
	PVOID GdiCachedProcessHandle;
	ULONG GdiClientPID;
	ULONG GdiClientTID;
	PVOID GdiThreadLocaleInfo;
	PVOID UserReserved[5];
	PVOID GlDispatchTable[0x118];
	ULONG GlReserved1[0x1A];
	PVOID GlReserved2;
	PVOID GlSectionInfo;
	PVOID GlSection;
	PVOID GlTable;
	PVOID GlCurrentRC;
	PVOID GlContext;
	NTSTATUS LastStatusValue;
	UNICODE_STRING StaticUnicodeString;
	WCHAR StaticUnicodeBuffer[0x105];
	PVOID DeallocationStack;
	PVOID TlsSlots[0x40];
	LIST_ENTRY TlsLinks;
	PVOID Vdm;
	PVOID ReservedForNtRpc;
	PVOID DbgSsReserved[0x2];
	ULONG HardErrorDisabled;
	PVOID Instrumentation[0x10];
	PVOID WinSockData;
	ULONG GdiBatchCount;
	ULONG Spare2;
	ULONG Spare3;
	ULONG Spare4;
	PVOID ReservedForOle;
	ULONG WaitingOnLoaderLock;
	PVOID StackCommit;
	PVOID StackCommitMax;
	PVOID StackReserved;
} TEB, *PTEB;


 bool Int2DCheck()
{
	__try
	{
		__asm
		{
			int 0x2d
			xor eax, eax
			add eax, 2
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return false;
	}

	return true;
}

 bool IsDbgPresentPrefixCheck()
{
	__try
	{
		__asm __emit 0xF3 // 0xF3 0x64 disassembles as PREFIX REP:
		__asm __emit 0x64
		__asm __emit 0xF1 // One byte INT 1
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return false;
	}

	return true;
}

bool checkGlobalFlags()
{
	DWORD NtGlobalFlags;
	__asm
	{
		mov eax, fs:[30h]
		mov eax, [eax + 68h]
		mov NtGlobalFlags, eax
	}

	if (NtGlobalFlags & 0x70)
		return true;

	return false;
}

DWORD GetProcessIdByName(LPCTSTR name)
{
	PROCESSENTRY32 pe32;
	HANDLE snapshot = NULL;
	DWORD pid = 0;

	snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snapshot != INVALID_HANDLE_VALUE) {
		pe32.dwSize = sizeof(PROCESSENTRY32);

		if (Process32First(snapshot, &pe32)) {
			do {
				std::string sName = pe32.szExeFile;
				std::transform(sName.begin(), sName.end(), sName.begin(), ::tolower);

				if (!lstrcmp(sName.c_str(), name)) {
					pid = pe32.th32ProcessID;
					break;
				}
			} while (Process32Next(snapshot, &pe32));
		}

		CloseHandle(snapshot);
	}

	return pid;
}

void cSecurity::CheckAllPorcesses()
{
	std::vector<std::string> m_processList;
	m_processList.push_back(charenc("ollydbg.exe"));
	m_processList.push_back(charenc("wireshark.exe"));
	m_processList.push_back(charenc("lordpe.exe"));
	m_processList.push_back(charenc("hookshark.exe"));
	m_processList.push_back(charenc("idag.exe"));
	m_processList.push_back(charenc("MPGH Virus Scan Tool v6.exe"));

	for (unsigned int ax = 0; ax < m_processList.size(); ax++)
	{
		std::string sProcess = m_processList.at(ax);
		if (GetProcessIdByName(sProcess.c_str()) != 0)
		{
			exit(0);
		}
	}
}

inline uint16_t getCpuHash()
{
	int cpuinfo[4] = { 0, 0, 0, 0 };
	__cpuid(cpuinfo, 0);
	uint16_t hash = 0;
	auto ptr = reinterpret_cast<uint16_t*>(&cpuinfo[0]);
	for (auto i = 0; i < 10; i++)
		hash += ptr[i];
	return hash;
}

uint16_t GetHWID()
{
	static char computerName[1024];
	DWORD size = 1024;
	GetComputerName(computerName, &size);

	DWORD serialNum = 0;
	GetVolumeInformation(("c:\\"), nullptr, 0, &serialNum, nullptr, nullptr, nullptr, 0);
	auto hash = static_cast<uint16_t>((serialNum + (serialNum >> 86)) & 0xFFFF);
	hash = hash + static_cast<uint16_t>(((int)computerName[0] + ((int)computerName[0] >> 26)) & 0xFFFF);

	return (hash / 2 * 15 * (768 % 678));
}



inline BOOL CanOpenCsrss()
{
	HANDLE hCsrss = 0;

	hCsrss = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetProcessIdByName(charenc("csrss.exe")));

	if (hCsrss != NULL)
	{
		CloseHandle(hCsrss);
		return TRUE;
	}
	else
		return FALSE;

}


PPEB_DUMMY __declspec(naked) GetPEB(void)
{
	_asm
	{
		mov eax, fs:[0x30];
		retn;
	}
}

DWORD cSecurity::HideMod(HMODULE mod)
{
	DWORD MBA;
	DWORD MBS;
	PTEB pTEB;
	PPEB_LDR_DATA pLDR;
	PLIST_ENTRY pM, pCM;
	PLDR_MODULE pMM;
	int M = 0, L = 0, I = 0, temp = 0;
	IMAGE_DOS_HEADER *DOSH = (IMAGE_DOS_HEADER*)mod;
	IMAGE_NT_HEADERS *NTH = NULL;
	DWORD OP;
	__asm
	{
		xor eax, eax;
		mov eax, fs:[0x18];
		mov pTEB, eax;
	}
	pLDR = pTEB->Peb->LoaderData;
	if (DOSH->e_magic != IMAGE_DOS_SIGNATURE) return 0;
	NTH = ((PIMAGE_NT_HEADERS)((DWORD)(DOSH)+(DWORD)(DOSH->e_lfanew)));
	if (NTH->Signature != IMAGE_NT_SIGNATURE) return 0;
	MBS = NTH->OptionalHeader.SizeOfImage;
	MBA = NTH->OptionalHeader.ImageBase;

	if (!pLDR) return 1;
	for (int m = 0; m <= 2; m++)
	{
		if (m == 0) pM = &(pLDR->InMemoryOrderModuleList);
		if (m == 1) pM = &(pLDR->InLoadOrderModuleList);
		if (m == 2) pM = &(pLDR->InInitializationOrderModuleList);
		for (pCM = pM->Flink; pCM != pM; pCM = pCM->Flink)
		{
			if (m == 0) pMM = CONTAINING_RECORD(pCM, LDR_MODULE, InMemoryOrderModuleList);
			if (m == 1) pMM = CONTAINING_RECORD(pCM, LDR_MODULE, InLoadOrderModuleList);
			if (m == 2) pMM = CONTAINING_RECORD(pCM, LDR_MODULE, InInitializationOrderModuleList);
			if ((DWORD)pMM->BaseAddress == MBA && (DWORD)pMM->SizeOfImage == MBS)
			{
				pCM->Blink->Flink = pCM->Flink;
				pCM->Flink->Blink = pCM->Blink;
			}
		}
	}
	VirtualProtect((LPVOID)DOSH, NTH->OptionalHeader.SizeOfHeaders, PAGE_EXECUTE_READWRITE, &OP);
	memset((LPVOID)DOSH, 0, NTH->OptionalHeader.SizeOfHeaders);
	VirtualProtect((LPVOID)DOSH, NTH->OptionalHeader.SizeOfHeaders, OP, &OP);
	return 3;
}


void cSecurity::HideModuleFromPEB(HINSTANCE hInstance)
{
	PPEB_DUMMY PEB = GetPEB();

	PLIST_ENTRY FirstEntryInLoadOrder = (PLIST_ENTRY)&PEB->LDR_Data->InLoadOrderModuleList;
	PLIST_ENTRY FirstEntryInMemoryOrder = (PLIST_ENTRY)&PEB->LDR_Data->InMemoryOrderModuleList;
	PLIST_ENTRY FirstEntryInInitOrder = (PLIST_ENTRY)&PEB->LDR_Data->InInitializationOrderModuleList;

	for (PLIST_ENTRY TempEntry = FirstEntryInLoadOrder->Flink; TempEntry != FirstEntryInLoadOrder; TempEntry = TempEntry->Flink)
	{
		PLDR_MODULE TempModule = (PLDR_MODULE)((DWORD)TempEntry - 0 * sizeof(LIST_ENTRY));
		if (TempModule->BaseAddress == hInstance)
		{
			TempEntry->Blink->Flink = TempEntry->Flink;
			TempEntry->Flink->Blink = TempEntry->Blink;
			break;
		}
	}

	for (PLIST_ENTRY TempEntry = FirstEntryInMemoryOrder->Flink; TempEntry != FirstEntryInMemoryOrder; TempEntry = TempEntry->Flink)
	{
		PLDR_MODULE TempModule = (PLDR_MODULE)((DWORD)TempEntry - 1 * sizeof(LIST_ENTRY));
		if (TempModule->BaseAddress == hInstance)
		{
			TempEntry->Blink->Flink = TempEntry->Flink;
			TempEntry->Flink->Blink = TempEntry->Blink;
			break;
		}
	}

	for (PLIST_ENTRY TempEntry = FirstEntryInInitOrder->Flink; TempEntry != FirstEntryInInitOrder; TempEntry = TempEntry->Flink)
	{
		PLDR_MODULE TempModule = (PLDR_MODULE)((DWORD)TempEntry - 2 * sizeof(LIST_ENTRY));
		if (TempModule->BaseAddress == hInstance)
		{
			TempEntry->Blink->Flink = TempEntry->Flink;
			TempEntry->Flink->Blink = TempEntry->Blink;
			break;
		}
	}
}
void cSecurity::RemovePeHeader(DWORD ModuleBase)
{
	PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)ModuleBase;
	PIMAGE_NT_HEADERS pNTHeader = (PIMAGE_NT_HEADERS)((DWORD)pDosHeader + (DWORD)pDosHeader->e_lfanew);

	if (pNTHeader->Signature != IMAGE_NT_SIGNATURE)
		return;

	if (pNTHeader->FileHeader.SizeOfOptionalHeader)
	{
		DWORD Protect;
		WORD Size = pNTHeader->FileHeader.SizeOfOptionalHeader;
		VirtualProtect((void*)ModuleBase, Size, PAGE_EXECUTE_READWRITE, &Protect);
		RtlZeroMemory((void*)ModuleBase, Size);
		VirtualProtect((void*)ModuleBase, Size, Protect, &Protect);
	}
}
void cSecurity::HideModule(HANDLE hModule)
{
	PIMAGE_DOS_HEADER pDOSHeader = (PIMAGE_DOS_HEADER)hModule;
	if (pDOSHeader->e_magic == IMAGE_DOS_SIGNATURE)
	{
		PIMAGE_NT_HEADERS pNTHeader = (PIMAGE_NT_HEADERS)((DWORD)pDOSHeader + (DWORD)pDOSHeader->e_lfanew);
		if (pNTHeader->Signature == IMAGE_NT_SIGNATURE)
		{
			DWORD dwOld, dwSize = pNTHeader->OptionalHeader.SizeOfHeaders;
			if (VirtualProtect((LPVOID)pDOSHeader, dwSize, PAGE_READWRITE, &dwOld))
			{
				memset((void*)pDOSHeader, 0, dwSize);
				VirtualProtect((LPVOID)pDOSHeader, dwSize, dwOld, &dwOld);
			}
		}
		_TEB *pTeb = nullptr;
		_asm
		{
			mov eax, fs:[0x18]
			mov pTeb, eax
		}
		PLIST_ENTRY pList = &pTeb->Peb->LoaderData->InLoadOrderModuleList;
		for (PLIST_ENTRY pEntry = pList->Flink; pEntry != pList; pEntry = pEntry->Flink)
		{
			PLDR_MODULE pModule = (PLDR_MODULE)pEntry;
			if (pModule->BaseAddress == hModule)
			{
				pEntry = &pModule->InLoadOrderModuleList; pEntry->Blink->Flink = pEntry->Flink; pEntry->Flink->Blink = pEntry->Blink;
				memset(pEntry, 0, sizeof(LIST_ENTRY));
				pEntry = &pModule->InMemoryOrderModuleList; pEntry->Blink->Flink = pEntry->Flink; pEntry->Flink->Blink = pEntry->Blink;
				memset(pEntry, 0, sizeof(LIST_ENTRY));
				pEntry = &pModule->InInitializationOrderModuleList; pEntry->Blink->Flink = pEntry->Flink; pEntry->Flink->Blink = pEntry->Blink;
				memset(pEntry, 0, sizeof(LIST_ENTRY));
				pEntry = &pModule->HashTableEntry; pEntry->Blink->Flink = pEntry->Flink; pEntry->Flink->Blink = pEntry->Blink;
				memset(pEntry, 0, sizeof(LIST_ENTRY));
				memset(pModule->FullDllName.Buffer, 0, pModule->FullDllName.Length);
				memset(pModule, 0, sizeof(LDR_MODULE));
				break;
			}
		}
	}
}
void cSecurity::HideModuleXta(HINSTANCE hModule)
{
	DWORD dwPEB_LDR_DATA = 0;

	_asm
	{
		pushad;
		pushfd;
		mov eax, fs:[30h]
			mov eax, [eax + 0Ch]
			mov dwPEB_LDR_DATA, eax
			mov esi, [eax + 0Ch]
			mov edx, [eax + 10h]

			LoopInLoadOrderModuleList :
			lodsd
			mov esi, eax
			mov ecx, [eax + 18h]
			cmp ecx, hModule
			jne SkipA
			mov ebx, [eax]
			mov ecx, [eax + 4]
			mov[ecx], ebx
			mov[ebx + 4], ecx
			jmp InMemoryOrderModuleList
			SkipA :
		cmp edx, esi
			jne LoopInLoadOrderModuleList

			InMemoryOrderModuleList :
		mov eax, dwPEB_LDR_DATA
			mov esi, [eax + 14h]
			mov edx, [eax + 18h]

			LoopInMemoryOrderModuleList :
			lodsd
			mov esi, eax
			mov ecx, [eax + 10h]
			cmp ecx, hModule
			jne SkipB
			mov ebx, [eax]
			mov ecx, [eax + 4]
			mov[ecx], ebx
			mov[ebx + 4], ecx
			jmp InInitializationOrderModuleList
			SkipB :
		cmp edx, esi
			jne LoopInMemoryOrderModuleList

			InInitializationOrderModuleList :
		mov eax, dwPEB_LDR_DATA
			mov esi, [eax + 1Ch]
			mov edx, [eax + 20h]

			LoopInInitializationOrderModuleList :
			lodsd
			mov esi, eax
			mov ecx, [eax + 08h]
			cmp ecx, hModule
			jne SkipC
			mov ebx, [eax]
			mov ecx, [eax + 4]
			mov[ecx], ebx
			mov[ebx + 4], ecx
			jmp Finished
			SkipC :
		cmp edx, esi
			jne LoopInInitializationOrderModuleList

			Finished :
		popfd;
		popad;
	}
}
bool cSecurity::DestroyModuleHeader(HMODULE hModule)
{
	DWORD dwStartOffset = (DWORD)hModule;

	IMAGE_DOS_HEADER *pDosHeader = (PIMAGE_DOS_HEADER)dwStartOffset;
	if (pDosHeader->e_magic != IMAGE_DOS_SIGNATURE)
		return false;

	IMAGE_NT_HEADERS *pNtHeader = (PIMAGE_NT_HEADERS)(dwStartOffset + pDosHeader->e_lfanew);
	if (pNtHeader->Signature != IMAGE_NT_SIGNATURE)
		return false;

	DWORD dwOldProtection = NULL;
	if (!VirtualProtect((PVOID)hModule, pNtHeader->OptionalHeader.SizeOfHeaders, PAGE_EXECUTE_READWRITE, &dwOldProtection))
		return false;

	ZeroMemory((PVOID)hModule, pNtHeader->OptionalHeader.SizeOfHeaders);
	VirtualProtect((PVOID)hModule, pNtHeader->OptionalHeader.SizeOfHeaders, dwOldProtection, &dwOldProtection);

	return true;
}

int HWIDS[] =
{
	38400,//Ich
	52824,//S4itama
	41688,//Luda
	18878,//Hazey
	25916,//jan
    52066,//Vane88
	54954,//peer
    39892,//mike
	31126,//zx8p
	45954,//crypto
	37064,//onurb,
	11780,//Avalanche
	24084,//danny
	53958,//muentzee
	58144,//xBlood
	52270,//nina und jule
	21272,//steven
	35698,//Toaster
	1122,//Zimty
	25498,//diego
	63892,//bilo
	38998,//SD
	34462,//nicolas
	14848,//tobi
	34112,//N4ffit
	55118,//Mike austria guy
	21018,//klausi invitd by toasty 1 monat starting 14.11
	4064,//jaffa 1 month starting 25.11
	8736,//justus 1 month starting 28.11
	48424,//Pr1x 1 month starting 11.11
	42812,//Rat 1 month Starting 30.11
	26982,//jay 1 month starting 30.11
	//53628,//bujasm 1 month Starting 25.11  NEED TO PAY!!! 1 descember
	40694,//lit/john 1 month Starting 10.12
	55226,//tecc  1 month starting 10.12
	41570//Casper420 1 month starting 10.12



};

void cSecurity::Check()
{
	VMProtectBeginUltra("chek");

	if (Int2DCheck())
		exit(0);

	if (IsDbgPresentPrefixCheck())
		exit(0);

	if (checkGlobalFlags())
		exit(0);

	time_t now = time(0);
	tm *ltm = localtime(&now);

	if (1900 + ltm->tm_year != 2017 || (1 + ltm->tm_mon) > 12 || (1 + ltm->tm_mday) > 24)  //subs
	{
		MessageBox(0, VMProtectDecryptStringA("Subscription Over, please Contact Ferrity"), VMProtectDecryptStringA("FH4x"), MB_OK);
		exit(0);
	}


	uint16_t curHWID = GetHWID();

	bool ok = false;

	for (int i = 0; i < ARRAYSIZE(HWIDS); i++)
	{
		if (curHWID == HWIDS[i])
		{
			ok = true;
			break;
		}
	}

	if (ok == false)
	{
		MessageBox(0, VMProtectDecryptStringA("Wrong HWID, please Contact Ferrity"), VMProtectDecryptStringA("FH4x"), MB_OK);
		exit(0);
	}

	VMProtectEnd();
}
>>>>>>> 4d5615fbb2fcbb0d8657fa851f63b1f3d1b78c6f

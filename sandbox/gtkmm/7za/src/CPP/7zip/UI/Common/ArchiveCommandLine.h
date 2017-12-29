// ArchiveCommandLine.h

#ifndef __ARCHIVE_COMMAND_LINE_H
#define __ARCHIVE_COMMAND_LINE_H

#include "../../../Common/CommandLineParser.h"
#include "../../../Common/Wildcard.h"

#include "Extract.h"
#include "HashCalc.h"
#include "Update.h"

struct CArcCmdLineException : public UString
{
  CArcCmdLineException(const char *a, const wchar_t *u = NULL);
};

namespace NCommandType {
enum EEnum
{
  kAdd = 0,
  kUpdate,
  kDelete,
  kTest,
  kExtract,
  kExtractFull,
  kList,
  kBenchmark,
  kInfo,
  kHash,
  kRename
};
} // namespace NCommandType

struct CArcCommand
{
  NCommandType::EEnum CommandType;

  bool IsFromExtractGroup() const;
  bool IsFromUpdateGroup() const;
  bool IsTestCommand() const { return CommandType == NCommandType::kTest; }
  NExtract::NPathMode::EEnum GetPathMode() const;
};

enum
{
  k_OutStream_disabled = 0,
  k_OutStream_stdout = 1,
  k_OutStream_stderr = 2
};

struct CArcCmdLineOptions
{
  bool HelpMode;

  bool LargePages;
  bool CaseSensitiveChange;
  bool CaseSensitive;

  bool IsInTerminal;
  bool IsStdOutTerminal;
  bool IsStdErrTerminal;
  bool StdInMode;
  bool StdOutMode;
  bool EnableHeaders;

  bool YesToAll;
  bool ShowDialog;
  NWildcard::CCensor Censor;

  CArcCommand Command;
  UString ArchiveName;

  bool PasswordEnabled;
  UString Password;

  bool TechMode;
  bool ShowTime;
  
  UStringVector HashMethods;

  bool AppendName;
  NWildcard::CCensor arcCensor;
  UString ArcName_for_StdInMode;

  CObjectVector<CProperty> Properties;

  CExtractOptionsBase ExtractOptions;

  CBoolPair NtSecurity;
  CBoolPair AltStreams;
  CBoolPair HardLinks;
  CBoolPair SymLinks;

  CUpdateOptions UpdateOptions;
  CHashOptions HashOptions;
  UString ArcType;
  UStringVector ExcludedArcTypes;
  
  unsigned Number_for_Out;
  unsigned Number_for_Errors;
  unsigned Number_for_Percents;
  unsigned LogLevel;

  // Benchmark
  UInt32 NumIterations;

  CArcCmdLineOptions():
      LargePages(false),
      CaseSensitiveChange(false),
      CaseSensitive(false),

      StdInMode(false),
      StdOutMode(false),

      Number_for_Out(k_OutStream_stdout),
      Number_for_Errors(k_OutStream_stderr),
      Number_for_Percents(k_OutStream_stdout),

      LogLevel(0)
  {
  };
};

class CArcCmdLineParser
{
  NCommandLineParser::CParser parser;
public:
  CArcCmdLineParser();
  void Parse1(const UStringVector &commandStrings, CArcCmdLineOptions &options);
  void Parse2(CArcCmdLineOptions &options);
};

HRESULT EnumerateDirItemsAndSort(
    NWildcard::CCensor &censor,
    NWildcard::ECensorPathMode pathMode,
    const UString &addPathPrefix,
    UStringVector &sortedPaths,
    UStringVector &sortedFullPaths,
    CDirItemsStat &st,
    IDirItemsCallback *callback);

#endif

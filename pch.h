// pch.h: esse é um arquivo de cabeçalho pré-compilado.
// Os arquivos listados a seguir são compilados somente uma vez, melhorando o desempenho dos builds futuros.
// Isso também afeta o desempenho do IntelliSense, incluindo a conclusão de código e muitos recursos de navegação de código.
// No entanto, os arquivos listados aqui serão TODOS recompilados se qualquer um deles for atualizado entre builds.
// Não adicione aqui arquivos que você atualizará com frequência, pois isso anula a vantagem de desempenho.

#ifndef PCH_H
#define PCH_H

#ifdef __cplusplus
#include <cpr/cpr.h>
#include <plog/Appenders/ConsoleAppender.h>
#include <plog/Formatters/MessageOnlyFormatter.h>
#include <plog/Initializers/RollingFileInitializer.h>
#include <plog/Log.h>

#include <array>
#include <atomic>
#include <cctype>
#include <codecvt>
#include <cstdint>
#include <cwchar>
#include <deque>
#include <filesystem>
#include <fstream>
#include <future>
#include <iostream>
#include <memory>
#include <mutex>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <variant>
#include <vector>

using std::int16_t;
using std::int32_t;
using std::int64_t;
using std::int8_t;
using std::uint16_t;
using std::uint32_t;
using std::uint64_t;
using std::uint8_t;
#endif

// adicione os cabeçalhos que você deseja pré-compilar aqui
#include "framework.h"

#define SetThreadDescription(x, y)

#endif //PCH_H

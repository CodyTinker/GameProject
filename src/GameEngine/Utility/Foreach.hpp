#ifndef ENGINE_FOREACH_HPP
#define ENGINE_FOREACH_HPP

// Preprocessor trick to allow nested loops
#define ENGINE_PP_CAT_IMPL(a, b) a ## b
#define ENGINE_PP_CAT(a, b) ENGINE_PP_CAT_IMPL(a, b)
#define ENGINE_ID(identifier) ENGINE_PP_CAT(auroraDetail_, identifier)
#define ENGINE_LINE_ID(identifier) ENGINE_PP_CAT(ENGINE_ID(identifier), __LINE__)


// Macro to emulate C++11 range-based for loop
// Instead of for (decl : range) you write FOREACH(decl, range) as in the following example
//
// std::vector<int> v = ...;
// FOREACH(int& i, v)
// {
//     i += 2;
// }
#define FOREACH(declaration, container)																											\
	if (bool ENGINE_LINE_ID(broken) = false) {} else																								\
	for (auto ENGINE_LINE_ID(itr) = (container).begin(); ENGINE_LINE_ID(itr) != (container).end() && !ENGINE_LINE_ID(broken); ++ENGINE_LINE_ID(itr))	\
	if (bool ENGINE_LINE_ID(passed) = false) {} else																								\
	if (ENGINE_LINE_ID(broken) = true, false) {} else																								\
	for (declaration = *ENGINE_LINE_ID(itr); !ENGINE_LINE_ID(passed); ENGINE_LINE_ID(passed) = true, ENGINE_LINE_ID(broken) = false)

#endif // ENGINE_FOREACH_HPP

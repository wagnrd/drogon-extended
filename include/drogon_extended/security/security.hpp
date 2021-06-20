#ifndef DROGON_EXTENDED_SECURITY_HPP
#define DROGON_EXTENDED_SECURITY_HPP

#include <drogon/HttpResponse.h>
#include <drogon/HttpRequest.h>

#define MULTI_SECURITY_GUARD(authorizationConfig1, boolOperator, authorizationConfig2)          \
    auto authorization = request->getHeader("Authorization");                                   \
    bool isUnauthorized;                                                                        \
    bool isUnauthorized1;                                                                       \
    bool isUnauthorized2;                                                                       \
                                                                                                \
    authorizationConfig1                                                                        \
    isUnauthorized1 = isUnauthorized;                                                           \
                                                                                                \
    authorizationConfig2                                                                        \
    isUnauthorized2 = isUnauthorized;                                                           \
                                                                                                \
    if (isUnauthorized1 boolOperator isUnauthorized2)                                           \
    {                                                                                           \
        auto response = ExceptionMapper::build_exception_response(                              \
                                drogon::HttpStatusCode::k401Unauthorized,                       \
                                "Authorization failed",                                         \
                                "Provided authorization is invalid: '" + authorization + "'"    \
        );                                                                                      \
        callback(response);                                                                     \
        return;                                                                                 \
    }

#define SECURITY_GUARD(authorizationConfig) MULTI_SECURITY_GUARD(authorizationConfig, AND, DUMMY_AUTHORIZATION(true))

#define OR ||
#define AND &&

#define DUMMY_AUTHORIZATION(boolValue) isUnauthorized = boolValue;

#define API_KEY(apiKey)                 \
    isUnauthorized = authorization != apiKey; \

#endif //DROGON_EXTENDED_SECURITY_HPP

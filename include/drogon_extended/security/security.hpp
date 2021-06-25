#ifndef DROGON_EXTENDED_SECURITY_HPP
#define DROGON_EXTENDED_SECURITY_HPP

#include <jwt-cpp/jwt.h>
#include <drogon/HttpResponse.h>
#include <drogon/HttpRequest.h>

void test()
{
    auto decodedJwtToken = jwt::decode("");
    auto verifier = jwt::verify()
            .allow_algorithm(jwt::algorithm::rs256{""})
            .with_issuer("");
    std::error_code error;
    verifier.verify(decodedJwtToken, error);
    if (error != jwt::error::rsa_error::ok)
    {
    }
}

#define API_KEY(apiKey) isUnauthorized = authorization != (apiKey);

#define JWT_TOKEN(issuer, publicKey)                                                    \
    auto tokenType = authorization.substr(0, 6);                                        \
                                                                                        \
    if (tokenType != "Bearer")                                                          \
    {                                                                                   \
        LOG_DEBUG << "Token type '" << tokenType << "' is not Bearer!";                 \
                                                                                        \
        auto response = ExceptionMapper::build_exception_response(                      \
                                drogon::HttpStatusCode::k401Unauthorized,               \
                                "Authorization failed",                                 \
                                "Provided token type is invalid: '" + tokenType + "'"   \
        );                                                                              \
        callback(response);                                                             \
        return;                                                                         \
    }                                                                                   \
                                                                                        \
    auto jwtToken = authorization.substr(7);                                            \
    auto decodedJwtToken = jwt::decode(jwtToken);                                       \
                                                                                        \
    auto verifier = jwt::verify()                                                       \
            .allow_algorithm(jwt::algorithm::rs256{publicKey})                          \
            .with_issuer(issuer);                                                       \
    verifier.verify(decodedJwtToken);                                                   \
                                                                                        \
    if (jwt::error::rsa_error::ok

#define SECURITY_GUARD(authorizationConfig)                                                     \
    auto authorization = request->getHeader("Authorization");                                   \
    LOG_DEBUG << "Authorization: " << authorization;                                            \
                                                                                                \
    bool isUnauthorized;                                                                        \
    authorizationConfig                                                                         \
                                                                                                \
    if (isUnauthorized)                                                                         \
    {                                                                                           \
        auto response = ExceptionMapper::build_exception_response(                              \
                                drogon::HttpStatusCode::k401Unauthorized,                       \
                                "Authorization failed",                                         \
                                "Provided authorization is invalid: '" + authorization + "'"    \
        );                                                                                      \
        callback(response);                                                                     \
        return;                                                                                 \
    }

#endif //DROGON_EXTENDED_SECURITY_HPP

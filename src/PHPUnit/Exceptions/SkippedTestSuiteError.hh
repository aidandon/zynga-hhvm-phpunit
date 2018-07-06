<?hh // strict

/*
 * This file is part of PHPUnit.
 *
 * (c) Sebastian Bergmann <sebastian@phpunit.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPUnit\Exceptions;

use PHPUnit\Exceptions\AssertionFailedError;
use PHPUnit\Interfaces\SkippedTest;

/**
 * Extension to AssertionFailedError to mark the special
 * case of a skipped test suite.
 *
 * @since Class available since Release 3.1.0
 */
class SkippedTestSuiteError extends AssertionFailedError implements SkippedTest {
}

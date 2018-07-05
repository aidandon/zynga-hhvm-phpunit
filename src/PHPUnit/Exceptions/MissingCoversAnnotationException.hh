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
use PHPUnit\Exceptions\RiskyTestError;

/**
 * Extension to AssertionFailedError to mark a test as risky
 * when it does not have a @covers annotation but is expected to have one.
 *
 * @since Class available since Release 5.3.0
 */
class MissingCoversAnnotationException extends RiskyTestError {
}
